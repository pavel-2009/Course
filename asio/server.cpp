#include <boost/asio.hpp>
#include <array>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session>
{
private:
    tcp::socket socket_;
    std::array<char, 1024> buffer_;

public:
    explicit Session(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    void start()
    {
        read();
    }

private:
    void read()
    {
        auto self = shared_from_this();

        socket_.async_read_some(
            boost::asio::buffer(buffer_),

            [self](const boost::system::error_code& ec,
                   std::size_t bytes)
            {
                if (!ec)
                {
                    self->write(bytes);
                }
            });
    }

    void write(std::size_t bytes)
    {
        auto self = shared_from_this();

        boost::asio::async_write(
            socket_,
            boost::asio::buffer(buffer_.data(), bytes),

            [self](const boost::system::error_code& ec,
                   std::size_t)
            {
                if (!ec)
                {
                    self->read();
                }
            });
    }
};

int main()
{
    boost::asio::io_context io;

    tcp::acceptor acceptor(
        io,
        tcp::endpoint(tcp::v4(), 8080));

    std::function<void()> do_accept;

    do_accept = [&]()
    {
        acceptor.async_accept(
            [&](boost::system::error_code ec,
                tcp::socket socket)
            {
                if (!ec)
                {
                    std::cout << "Client connected\n";

                    std::make_shared<Session>(
                        std::move(socket))
                        ->start();
                }

                do_accept();
            });
    };

    do_accept();

    std::cout << "Server started on port 8080\n";

    io.run();
}