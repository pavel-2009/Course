#include <arpa/inet.h>
#include <unistd.h>

#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>


bool send_all(
    int sock,
    const void* buffer,
    size_t bytes_to_send
)
{
    size_t total_sent = 0;

    const char* ptr =
        static_cast<const char*>(buffer);

    while ( total_sent < bytes_to_send )
    {
        ssize_t sent = send(
            sock,
            ptr,
            bytes_to_send - total_sent,
            0
        );

        if ((sent == 0) || (sent < 0))
            return false;

        total_sent += sent;
        ptr += sent;
    }

    return true;
}


bool send_message(
    int sock,
    const std::string& message
) {

    uint32_t length = htonl(message.size()); // Длина сообщения в байтах

    if (!send_all(   // Отправляем длину сообщения
            sock,
            &length,
            sizeof(length))) 
    {
        return false;
    }

    if (!send_all(   // Отправляем само сообщение
            sock,
            message.data(),
            message.size())) 
    {
        return false;
    }

    return true;

}


int main() {

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server{};

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(sock, reinterpret_cast<sockaddr*>(&server), sizeof(server));

    while (true)
    {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        if (message == "exit") break;

        send_message(sock, message);
    }

    close(sock);

}
