#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

template<typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    std::atomic<Node*> head;

public:
    LockFreeStack() : head(nullptr) {}

    ~LockFreeStack() {
        // Cleanup remaining nodes
        Node* curr = head.load();
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void push(T value) {

        Node* new_node = new Node(value);
        new_node->next = head.load(std::memory_order_relaxed);

        while (!head.compare_exchange_weak(
            new_node->next,
            new_node,
            std::memory_order_release,
            std::memory_order_relaxed
        ));
    }

    bool pop(T& result) {

        Node* head_pop = head.load(std::memory_order_acquire);
        if (!head_pop) return false;

        while (!head.compare_exchange_weak(
            head_pop,
            head_pop->next,
            std::memory_order_release,
            std::memory_order_relaxed
        ));

        result = head_pop->data;
        delete head_pop; // ⚠️ Not safe in real lock-free systems
        return true;
    }

    bool empty() const {
        return head.load() == nullptr;
    }
};

void push_task(LockFreeStack<int>& stack, int thno) {
    for (int i = 0; i < 10; ++i) {
        auto val = (thno * 100) + i;
        stack.push(val);

        char outstr[50] = {0};
        sprintf(outstr, "\nThread : %d - Pushed : %d", thno, val);
        std::cout<<outstr;

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void pop_task(LockFreeStack<int>& stack, int thno) {
    int value;
    while (!stack.empty()) {
        if (stack.pop(value)) {
            // Uncomment if you want output (will slow down)
            // std::cout << "Popped: " << value << std::endl;
            
            char outstr[50] = {0};
            sprintf(outstr, "\n\t\tThread : %d - Poped : %d", thno, value);
            std::cout<<outstr;
            
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}

int main() {
    LockFreeStack<int> stack;

    const int num_threads = 4;
    //const int operations = 10;

    std::vector<std::thread> threads;

    // PUSH threads
    for (int i = 1; i < num_threads; ++i) {
        threads.emplace_back(push_task, std::ref(stack), i);
    }

    // POP threads
    for (int i = 1; i < num_threads; ++i) {
        threads.emplace_back(pop_task, std::ref(stack), i);
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    // Final check
    if (stack.empty()) {
        std::cout << std::endl << "Stack is empty after operations." << std::endl;
    } else {
        std::cout << std::endl << "Stack is NOT empty." << std::endl;
    }

    return 0;
}