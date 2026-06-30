import socket
import selectors
import os
import subprocess
import random
import sys
import time

START_HP = 80
IlLNESSES = ["reverse", "close"]

nft_commands = """
table inet filter {
    chain input {
        type filter hook input priority filter; policy drop;
        iifname "lo" accept
        ct state established,related accept
        tcp dport 22 accept
    }
}
"""

nft_open = """
table inet filter {
    chain input {
        type filter hook input priority filter; policy accept;
    }
}
"""

def apply_nft_rules(rules: str):
    """Безопасный вызов nftables"""
    try:
        process = subprocess.Popen(
            ["sudo", "nft", "-f", "-"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        stdout, stderr = process.communicate(input=rules)
        if process.returncode != 0:
            print(f"[-] Ошибка nftables: {stderr.strip()}", file=sys.stderr)
    except Exception as e:
        print(f"[-] Не удалось применить правила файрвола: {e}", file=sys.stderr)


class Monster:
    def __init__(self):
        self.hp = START_HP
        self.status = "medium"
        
    def set_status(self, new_status: str):
        """Централизованное управление состояниями и файрволом"""
        if self.status == new_status:
            return # Статус не изменился, ничего не делаем
            
        old_status = self.status
        self.status = new_status
        print(f"\n[!] МУТАЦИЯ: {old_status} -> {new_status} (HP: {self.hp})")
        
        # Реакция на смену состояний файрвола
        if new_status == "berserk":
            print("[*] Вход в regime БЕРСЕРК! Закрываю nftables...")
            apply_nft_rules(nft_commands)
        elif old_status == "berserk" and new_status != "berserk":
            print("[*] Выход из режима БЕРСЕРК. Открываю nftables...")
            apply_nft_rules(nft_open)
            
        # Реакция на смерть
        if new_status == "dead":
            print("☠️ ААААААААААААААААААААААААА!!!!! (Самоликвидация)")
            apply_nft_rules(nft_open) # Перед смертью возвращаем систему в исходное состояние
            try:
                os.remove(__file__)
            except Exception as e:
                print(f"Не удалось удалить файл: {e}")
            sys.exit(0)

    def lose(self):
        self.hp -= 1  
        self._sync_status()

    def heal(self):
        self.hp = min(self.hp + 20, 150) # Защита от бесконечного разгона HP
        self._sync_status()

    def calm(self):
        self.hp -= 15
        self._sync_status()

    def stat(self):
        return f"HP: {self.hp}, Status: {self.status}"

    def _sync_status(self):
        """Внутренний хелпер для расчета нового статуса на основе HP"""
        if self.hp <= 0:
            self.set_status("dead")
        elif self.hp < 20:
            self.set_status("ill")
        elif self.hp > 90:
            self.set_status("berserk")
        else:
            self.set_status("medium")

                
monster = Monster()  


def process_data(data: bytes):
    raw_data = data.decode('utf-8').strip()
    global monster
    answer = None
    
    # 1. Сначала обрабатываем управляющие команды
    match raw_data:
        case "heal":
            monster.heal()
            return f"Healed! {monster.stat()}"
            
        case "calm":
            monster.calm()
            return f"Calmed! {monster.stat()}"
            
        case "status":
            return monster.stat()
            
    # 2. Если это не команда, смотрим на текущие "эффекты" состояния монстра
    match monster.status:
        case "ill":
            illness = random.choice(IlLNESSES)
            if illness == "reverse":
                return raw_data[::-1]
            else:
                return "close"
            
        case "berserk":
            return "Ух, я зол!!!"
            
        case "medium":
            return f"Echo: {raw_data}"
            
        case _:
            return "Неизвестная команда"
            
        
selector = selectors.DefaultSelector()
        
        
def read_data(server_socket: socket.socket):
    try:
        client_sock, addr = server_socket.accept()
        print(f"[+] Подключен клиент с адресом {addr}")
        client_sock.setblocking(False)
        selector.register(client_sock, selectors.EVENT_READ, data=accept_data)
    except Exception as e:
        print(f"[-] Ошибка при accept: {e}")
    
    
def accept_data(client_socket: socket.socket):
    try:
        data = client_socket.recv(1024)
        
        if data:
            answer = process_data(data)
            
            if answer == "close":
                print("Упс, неполадочка, хи-хи... (Закрываем сокет из-за болезни)")
                selector.unregister(client_socket)
                client_socket.close()
            elif answer:
                client_socket.send((answer + "\n").encode('utf-8'))
                print(f"[>] Отправлено: {answer}")
            
        else:
            print("[-] Клиент отключился.")
            selector.unregister(client_socket)
            client_socket.close()
    
    except (ConnectionResetError, BrokenPipeError):
        print("[-] Соединение оборвано.")
        try:
            selector.unregister(client_socket)
        except:
            pass
        client_socket.close()
        
        
def main():
    global selector, monster
    
    server = socket.socket()
    server.setsockopt(
        socket.SOL_SOCKET,
        socket.SO_REUSEADDR,
        1
    )
    server.bind(('127.0.0.1', 5000))
    server.setblocking(False)
    server.listen(5)
    
    selector.register(server, selectors.EVENT_READ, data=read_data)
    
    print(f"[*] Кибер-Тамагочи запущен на 127.0.0.1:5000. Текущее HP: {monster.hp}")
    last_sleep_time = time.time()
    
    try:
        while True:
            # Уменьшаем тайм-аут ожидания событий, чтобы чаще проверять часы
            events = selector.select(timeout=0.1)
            
            for key, _ in events:
                callback = key.data
                callback(key.fileobj)
                
            now = time.time()
            if now - last_sleep_time >= 1.0:
                monster.lose()
                print(f"[Тик] {monster.stat()}")
                last_sleep_time = now
                
    except KeyboardInterrupt:
        print("\n[*] Сервер остановлен вручную. Сброс правил nftables...")
        apply_nft_rules(nft_open)
    finally:
        selector.close()

if __name__ == "__main__":
    main()
