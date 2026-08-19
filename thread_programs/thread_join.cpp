#include<thread>
#include<iostream>
#include<vector>

// function to run in thread
void run(std::string thname, int limit) {

    for (int i = 1; i <= limit; i++) {

        char out[50] = {0};
        // formating string to pring as it is because... 
        // std::cout << std::endl << thname.c_str() << " : " << i;
        // is not printing new line character in sequense and next string
        sprintf(out, "\n \t%s : %d", thname.c_str(), i);  
        std::cout<< out;

        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    char out[50] = {0};
    sprintf(out, "\n %s : finished", thname.c_str());  
    std::cout<< out;
}

int main() {

    // clear screen
    system("cls");

    // vector (container) for threads 
    std::vector<std::thread> threads;

    // start threads and push back in vector 
    threads.push_back(std::thread(&run, "thread-1", 5)); // or threads.emplace_back(run, "thread-1", 5);
    threads.push_back(std::thread(&run, "thread-2", 10)); // or threads.emplace_back(run, "thread-2", 10);
    threads.push_back(std::thread(&run, "thread-3", 15)); // or threads.emplace_back(run, "thread-3", 15);

    // join all threads to wait for programt termination till finishing all threads
    for (auto& thd : threads) {

        thd.join();
    }

    std::cout<<"\n All threads are finished";
    return 0;
}