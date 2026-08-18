#include<iostream>
#include<thread>
#include<chrono>

class MemoryOrders{

    private:
    int a = 0;
    std::atomic<bool>flag{false};
    public:
    void Thread1() {

        while(a < 20) {
         
            ++a;
            std::cout<<std::endl<<"Thread1 : "<<a;
            flag.store(true, std::memory_order_release);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    void Thread2() {

        while(a < 20) {
            while(!flag.load(std::memory_order_acquire)) {}
            std::cout<<std::endl<<"Thread2 : "<<a;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

int main() {
    MemoryOrders obj;
    std::thread th1(&MemoryOrders::Thread1, &obj);
    std::thread th2(&MemoryOrders::Thread2, &obj);
    th1.join();
    th2.join();
    return 0;
}