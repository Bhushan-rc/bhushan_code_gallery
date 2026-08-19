#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void reverseArray(int arr[], short size);
void bubbleSort(int arr[], short size);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);

void FinalResult(int arr[], short size, std::string act) {

    short last = size - 1;
    std::cout<<"\n\n\t"<<act.c_str()<<"\t:\t";
    for(short id = 0; id <= last; ++id) {

        std::cout<<arr[id]<<"  ";
    }
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

int main() {

    while(1) {

        system("cls");
        const short size = 5;
        int arr[size] = {9, 8, 7, 6, 5};
        FinalResult(arr, size, "Original Array");

        std::cout<<std::endl;
        std::cout<<"\n\t1. Reverse";
        std::cout<<"\n\t2. Bubble Sort";
        std::cout<<"\n\t3. Selection Sort";
        std::cout<<"\n\t4. Insertion Sort";
        std::cout<<"\n\t5. Merge Sort";
        std::cout<<"\n\t6. Exit";
        std::cout<<"\n\t#. Select Action : ";

        int action = 0;
        std::cin>>action;

        switch(action) {

            case 1: 
                reverseArray(arr, size);    
                FinalResult(arr, size, "Reversed Array");
            break;
            case 2: 
                bubbleSort(arr, size);
                FinalResult(arr, size, "Bubble Sort");
            break;
            case 3: 
                selectionSort(arr, size);
                FinalResult(arr, size, "Selection Sort");
            break;
            case 4: 
                insertionSort(arr, size);
                FinalResult(arr, size, "Insertion Sort");
            break;
            case 5: 
                mergeSort(arr, 0, size - 1);
                FinalResult(arr, size, "Merg Sort");
            break;
            case 6:     
                return 0;
            break;
            default:
                std::cout << "\n\tInvalid input";
            break;
        }

        std::cout << "\n";
        std::cout << "\n\t1. Continue";
        std::cout << "\n\t2. Exit";
        std::cout << "\n\t#. Select Action : ";

        action = 0;
        std::cin >> action;
        if(action != 1)
            break;
    }
    return 0;
}

void reverseArray(int arr[], short size) {

    std::cout<<std::endl<<"\tAlgorithm\t:\t";
    for(short k = 0; k < size; ++k) {
        std::cout<<arr[k]<<"  ";
    }

    short rid = size - 1;
    short mid = rid / 2;
    for(short fid = 0; fid < mid; ++fid) {

        int val = arr[fid];
        arr[fid] = arr[rid];
        arr[rid] = val;
        --rid;

        std::cout<<std::endl<<"\tStep-"<<fid + 1<<"\t\t:\t";
        for(short i = 0; i < size; ++i) {
            std::cout<<arr[i]<<"  ";
        }
    }
}

void bubbleSort(int arr[], short size) {

    for(short id1 = 0; id1 < size - 1; ++id1) {

        std::cout<<"\n\tStep - [ *"<<id1 + 1<<"* ]\t:\t";
        showArray(arr, size, arr[0]);

        bool bSwapped = false;
        for(short id2 = 0; id2 < size - id1 - 1; ++id2) {

            int val = arr[id2];

            if(arr[id2] > arr[id2 + 1]) {

                arr[id2] = arr[id2 + 1];
                arr[id2 + 1] = val;

                bSwapped = true;
            }

            std::cout<<"\n\tStep - [ "<<id1 + 1<<":"<<id2 + 1<<" ]\t:\t";
            showArray(arr, size, val);
        }

        if(!bSwapped) {
            break;
        }
        std::cout<<std::endl;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIdx = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }

        std::swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i+1], arr[high]);

    return i + 1;
}

void merge(int arr[], int left, int mid, int right) {

    std::vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right) {

        if(arr[i] <= arr[j]) 
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while(i <= mid) {

        temp.push_back(arr[i]);
        i++;
    }

    while(j <= right) {

        temp.push_back(arr[j]);
        j++;
    }

    for(int k = left; k <= right; k++) {

        arr[k] = temp[k - left];
    }
}

void mergeSort(int arr[], int left, int right) {

    if(left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Here I am sorting left half
    mergeSort(arr, left, mid);

    // Here I am sorting right half
    mergeSort(arr, mid + 1, right);

    // Here I am merging both left and right half
    merge(arr, left, mid, right);
}