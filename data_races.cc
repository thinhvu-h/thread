#include <thread>
#include <string>
#include <chrono>
#include <iostream>

using namespace std::literals;

void print(std::string str) {
    for (int i = 0; i<5; i++) {
        std::cout << str[0] << str[1] << str[2] << std::endl;
        std::this_thread::sleep_for(50ms);
    }
}

int main() {
    std::thread t1{print, "abc"};
    std::thread t2{print, "123"};
    std::thread t3{print, "xyz"};
    
    t1.join();
    t2.join();
    t3.join();
}
