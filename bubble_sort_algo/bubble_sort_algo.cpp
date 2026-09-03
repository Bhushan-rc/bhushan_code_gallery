/*
    \author:    Bhushan R Chaudhari
    \brief:     Program explaining logic for bubble sort
*/

#include <iostream>
#include <thread>
#include <chrono>

void showResult(int arr[], short size, std::string act) {

    short last = size - 1;
    std::cout<<"\n\n\t"<<act.c_str()<<"\t:\t";

    std::cout << "\033[32m";
    for(short id = 0; id <= last; ++id) {

        std::cout<<arr[id]<<"  ";
    }
    std::cout << "\033[0m";

    std::cout<<std::endl;
}

void showArray(int arr[], short size, int shiftedValue = -1) {

    for(short id = 0; id < size; ++id) {

        if(arr[id] == shiftedValue) {

            std::cout << "\033[32m";
            std::cout<<arr[id]<<"  ";
            std::cout << "\033[0m";
        }
        else {

            std::cout<<arr[id]<<"  ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void bubbleSort(int arr[], short size) {

    for(short id1 = 0; id1 < size - 1; ++id1) {

        std::cout<<"\n\tStep - [ *"<<id1 + 1<<"* ]\t\t:\t";
        showArray(arr, size, arr[0]);

        bool bSwapped = false;
        for(short id2 = 0; id2 < size - id1 - 1; ++id2) {

            int val = arr[id2];

            if(arr[id2] > arr[id2 + 1]) {

                arr[id2] = arr[id2 + 1];
                arr[id2 + 1] = val;

                bSwapped = true;
            }

            std::cout<<"\n\tStep - [ "<<id1 + 1<<":"<<id2 + 1<<" ]\t\t:\t";
            showArray(arr, size, val);
        }

        if(!bSwapped) {
            break;
        }
        std::cout<<std::endl;
    }
}

int main() {

    system("cls");
    const short size = 5;
    int arr[size] = {9, 8, 5, 6, 7};

    showResult(arr, size, "Original Array\t");
    bubbleSort(arr, size);
    showResult(arr, size, "Bubble Sort Result");
    
    std::cout << "\n\n";
    return 0;
}