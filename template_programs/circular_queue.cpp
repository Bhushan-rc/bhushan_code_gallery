#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
#include<vector>

struct IntData {

    int data = 0;
    char state = ' ';
    IntData() {}
    IntData(int val) : data(val), state('W') {}
};

template<typename T, int _size>
class MyQueue {

    public:
    T my_queue[_size];
    std::mutex locker;

    int attempt_to_read = 0;
    int read = 0;
    int write = 0;
    
    void push(IntData &_in) {

        locker.lock();
        my_queue[write % _size] = _in;
        ++write;
        
        char txt[50] = {0};
        sprintf(txt, "  Pushed : [ %.2d ] >> [  ", _in.data);
        std::string str = txt;

        for(auto &out : my_queue) {

            sprintf(txt, "%c(%.2d)  ", out.state, out.data);
            str += txt;
        }
        str += "]\n";
        std::cout<< str;

        locker.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    bool pop() {

        locker.lock();

        if(read < write) {

            auto &_in = my_queue[read % _size];
            _in.state = 'R';
            ++read;
            
            char txt[50] = {0};
            sprintf(txt, "  Popped : [ %.2d ] >> [  ", _in.data);
            std::string str = txt;

            for(auto &out : my_queue) {

                sprintf(txt, "%c(%.2d)  ", out.state, out.data);
                str += txt;
            }
            str += "]\n";
            std::cout<< str;
            attempt_to_read = 0;
        }
        else {

            std::cout<< "  No new data available...\n";
            if(++attempt_to_read == 5) {

                locker.unlock();
                return false;
            }
        }

        locker.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        return true;
    }
};

class DataClass {

    public:
    
    // creating queue for int data of size 5
    MyQueue<IntData, 5> queue_int;
    
    void write(std::vector<int> &data) {

        for(auto &val : data) {

            queue_int.push(IntData(val));
        }
    }

    void read() {

        while(queue_int.pop()) { }
        std::cout<< "\n Read finish...";
    }
};

int main() {

    system("cls");
    std::cout << std::endl;

    // list of int data to push in queue
    std::vector<int>data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    DataClass obj;
    std::vector<std::thread> threads;
    threads.emplace_back(&DataClass::write, &obj, data);
    threads.emplace_back(&DataClass::read, &obj);

    for(auto &thd : threads) {

        if(thd.joinable())
            thd.join();
    }
    return 0;
}