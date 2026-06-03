"""Базовый сервер на чистом Python"""

import socket
import selectors
import os
import subprocess
import random
import sys


START_HP = 100


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
nft_open = """table inet filter {
    chain input {
        type filter hook input priority filter; policy accept;
    }
}
"""


class Monster:
    
    def __init__(self):
        self.hp = START_HP
        self.status = "medium"
        
    
    def lose(self):
        self.hp -= 1  
        if self.hp < 90:
            self.status = "medium"
        if self.hp < 20:
            self.status = "ill"  
            
        if self.hp < 0:
            self.status = "dead"
        
    def heal(self):
        self.hp += 20
        if self.hp > 20:
            self.status = "medium"
        if self.hp > 90:
            self.status = "berserk"
            
        if self.hp < 0:
            self.status = "dead"
        
    def calm(self):
        self.hp -= 15
        if self.hp < 90:
            self.status = "medium"
        if self.hp < 20:
            self.status = "ill"
            
        if self.hp < 0:
            self.status = "dead"
            
    
    def stat(self):
        print(self.hp, self.status)
            
            
monster = Monster()  


def process_data(data: bytes):
    data = data.decode('utf-8')
    
    global monster
    
    match data:
        case "heal":
            monster.heal()
            
        case "calm":
            monster.calm()
            
        case "status":
            monster.stat()
            
    current_status = monster.status
    
    match current_status:
        case "medium":
            # Проверим доступность nftables - должно быть открыто, иначе - ошибка
            process = subprocess.Popen(
                ["sudo", "nft", "-f", "-"],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )
            
            stdout, stderr = process.communicate(input=nft_open)
            
            if process.returncode == 0:
                print("Ну что, получил, собака!")
            else:
                print(f"Ошибка nftables:\n{stderr}", file=sys.stderr)
        
        case "ill":
            illness = random.choice(IlLNESSES)
            
            if illness == "reverse":
                answer = data[::-1]
                return answer
            
            else:
                answer = "close"
                return answer
            
        case "berserk":
            process = subprocess.Popen(
                ["sudo", "nft", "-f", "-"],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )
            
            # Закрываем nftables, чтобы никто не мог подключиться к серверу, кроме нас
            stdout, stderr = process.communicate(input=nft_commands)
            
            if process.returncode == 0:
                print("Ну что, получил, собака!")
            else:
                print(f"Ошибка nftables:\n{stderr}", file=sys.stderr)
                
                return "Ух, я зол!!!"
            
        case "dead":
            print("ААААААААААААААААААААААААА!!!!!")
            os.remove(__file__)
            
        
selector = selectors.DefaultSelector()
        
        
def read_data(server_socket: socket.socket):
    client_sock, addr = server_socket.accept()
    print(f"[+] Подключен клиент с адресом {addr}")
    
    client_sock.setblocking(False)
    selector.register(client_sock, selectors.EVENT_READ, data=accept_data)
    
    
def accept_data(client_socket: socket.socket):
    
    try:
        data = client_socket.recv(1024)
        
        if data:
            answer = process_data(data)
            client_socket.sendall(answer)
            
            if answer == "close":
                client_socket.close()
                print("Упс, неполадочка, хи-хи...")
            
        else:
            print("[-] Клиент отключился.")

            selector.unregister(client_socket)
            client_socket.close()
    
    except ConnectionResetError:
        print("[-] Соединение оборвано.")
        selector.unregister(client_socket)
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
    
    while True:
        
        # Устанавливаем таймаут в 1 секунду, чтобы на каждой отерации уменьшать здоровье монстра
        events = selector.select(timeout=1)
        
        for key, _ in events:
            callback = key.data
            callback(key.fileobj)
            
        monster.lose()
        
        
if __name__ == "__main__":
    main()
