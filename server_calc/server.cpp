#include <arpa/inet.h>
#include <unistd.h>

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>


bool recv_exact(
    int sock,
    void* buffer,
    size_t bytes_to_read
)
{
    size_t total_read = 0;

    char* ptr = static_cast<char*>(buffer);

    while (total_read < bytes_to_read)
    {
        ssize_t received = recv(
            sock,
            ptr,
            bytes_to_read - total_read,
            0
        );

        if (received <= 0)
            return false;

        total_read += received;
        ptr += received;
    }

    return true;
}

bool recv_message(
    int sock
)
{
    uint32_t length = 0; // Длина сообщения в байтах

    if (!recv_exact(   // Получаем длину сообщения
            sock,
            &length,
            sizeof(length))) 
    {
        return false;
    }

    length = ntohl(length); // Преобразуем длину из сетевого порядка байтов в порядок байтов хоста

    std::cout
        << "Message size = "
        << length
        << '\n';

    std::vector<char> buffer(length); // Буфер для хранения сообщения

    if (!recv_exact( // Получаем само сообщение
            sock,
            buffer.data(),
            length))
    {
        return false;
    }

    std::string message(
        buffer.begin(),
        buffer.end());

    std::cout
        << "Received: "
        << message
        << '\n';

    return true;
}

int main()
{
    int server_fd =
        socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(
        server_fd,
        reinterpret_cast<sockaddr*>(&address),
        sizeof(address));

    listen(server_fd, 5);

    std::cout
        << "Waiting client...\n";

    int client_fd =
        accept(server_fd, nullptr, nullptr);

    while (recv_message(client_fd))
    {
    }

    std::cout
        << "Client disconnected\n";

    close(client_fd);
    close(server_fd);
}