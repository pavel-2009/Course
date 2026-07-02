#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace std::chrono_literals;


awaitable<void> timer_task() {

    std::cout << "Coroutine started\n";

    steady_timer timer(co_await this_coro::executor);

    timer.expires_after(5s);

    std::cout << "First wait\n";

    co_await timer.async_wait(use_awaitable);

    timer.expires_after(5s);

    std::cout << "Second wait\n";

    co_await timer.async_wait(use_awaitable);

    std::cout << "Timer finished!\n";

    co_return;

}

int main() {
    io_context io;

    co_spawn(
        io,
        timer_task(),
        detached
    );

    io.run();
};
