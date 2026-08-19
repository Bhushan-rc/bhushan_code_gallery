#include<iostream>

template<typename T, std::size_t n>
class MyQueue {

    public:
    T my_queue[n];

    std::size_t head = 0;
    std::size_t tail = 0;
    std::size_t count = 0;

    void push(const T &val) {

        if(count == n) {

            std::cout << std::endl << " Queue is full, Push Rejected : " << val;
            return;
        }

        std::cout << "\n Pushed : " << val;
        my_queue[tail] = val;
        tail = (tail + 1) % n;
        ++count;
    }

    bool pop(T &val) {

        if(count == 0) {

            std::cout << std::endl << " Queue is empty";
            return false;
        }

        val = my_queue[head];
        head = (head + 1) % n;
        --count;

        return true;
    }
};

int main() {

    system("cls");
    
    // creating queue for int data of size 5
    MyQueue<int, 5> queue_int;
    
    std::cout << std::endl;

    // pushing int data in queue
    queue_int.push(1);
    queue_int.push(2);
    queue_int.push(3);
    queue_int.push(4);
    queue_int.push(5);
    queue_int.push(6); // will reject push operation as queue is full

    std::cout << std::endl;

    int ival = 0;
    // popping int data from queue
    while(queue_int.pop(ival))
        std::cout << "\n Popped : " << ival;

    // creating queue for string data of size 5
    MyQueue<std::string, 5> queue_string;

    std::cout << std::endl;

    // pushing string data in queue
    queue_string.push("JAN");
    queue_string.push("FEB");
    queue_string.push("MAR");
    queue_string.push("APR");
    queue_string.push("MAY");
    queue_string.push("JUN"); // will reject push operation as queue is full

    std::cout << std::endl;
    
    std::string sval = "";
    // popping string data from queue
    while(queue_string.pop(sval))
        std::cout << "\n Popped : " << sval;

    return 0;
}