/*
    \author:    Bhushan R Chaudhari
    \brief:     Program explaining logic for insertion sort
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

void showArray(int arr[], short size, short part, int shiftedValue = -1) {

    std::cout << "[  ";
    for(short id = 0; id < size; ++id) {

        if(arr[id] == shiftedValue) {

            std::cout << "\033[32m";
            std::cout << arr[id] << "  ";
            std::cout << "\033[0m";
        }
        else {

            std::cout << arr[id] << "  ";
        }
        
        if(id == part) {

            std::cout << "]  ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
}

void insertionSort(int arr[], int size)
{
    for(int id1 = 1; id1 < size; ++id1)
    {
        std::cout << "\n\tStep - [ *" << id1 << "* ]\t\t:\t";

        int key = arr[id1];
        int id2 = id1 - 1;

        showArray(arr, size, id1);

        while(id2 >= 0 && arr[id2] > key)
        {
            arr[id2 + 1] = arr[id2];
            --id2;
        }

        arr[id2 + 1] = key;

        std::cout << "\t\t\t\t\t";
        showArray(arr, size, id1, arr[id2 + 1]);
        //std::cout<<std::endl;
    }
}

int main() {

    system("cls");
    const short size = 5;
    int arr[size] = {9, 7, 8, 6, 5};
 
    showResult(arr, size, "Original Array\t");
    insertionSort(arr, size);
    showResult(arr, size, "Insertion Sort Result");
 
    std::cout << "\n\n";
    return 0;
}