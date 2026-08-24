#include<iostream>
#include<vector>

void showArray(int arr[], short size, std::string act);
void reverseArray(int arr[], short size);
void bubbleSort(int arr[], short size);
void selectionSort(int arr[], short size);
void insertionSort(int arr[], short size);
void mergeSort(int arr[], int left, int right);

int main() {

    bool run_it = true;
    while(run_it) {

        system("cls");
        const short size = 5;
        int arr[size] = {9, 4, 8, 2, 5};
        showArray(arr, size, "Original Array");

        std::cout<<std::endl;
        std::cout<<"\n\t1. Reverse";
        std::cout<<"\n\t2. Bubble Sort";
        std::cout<<"\n\t3. Selection Sort";
        std::cout<<"\n\t4. Insertion Sort";
        std::cout<<"\n\t5. Merg Sort";
        std::cout<<"\n\t6. Exit";
        std::cout<<"\n\t#. Select Action : ";

        int action = 0;
        std::cin>>action;

        switch(action) {

            case 1: 
                reverseArray(arr, size);    
                showArray(arr, size, "Reversed Array");
            break;
            case 2: 
                bubbleSort(arr, size);
                showArray(arr, size, "Bubble Sort");
            break;
            case 3: 
                selectionSort(arr, size);
                showArray(arr, size, "Selection Sort");
            break;
            case 4: 
                insertionSort(arr, size);
                showArray(arr, size, "Insertion Sort");
            break;
            case 5: 
                mergeSort(arr, 0, size - 1);
                showArray(arr, size, "Merg Sort");
            break;
            case 6: 
                run_it = false;    
                return 0;
            break;
            default:
                std::cout<<"\n\tInvalid input";
            break;
        }

        std::cout<<"\n";
        std::cout<<"\n\t1. Continue";
        std::cout<<"\n\t2. Exit";
        std::cout<<"\n\t#. Select Action : ";

        action = 0;
        std::cin>>action;
        if(action != 1)
            run_it = false;
    }
}

void showArray(int arr[], short size, std::string act) {

    short last = size - 1;
    std::cout<<"\n\n\t"<<act.c_str()<<"\t:\t";
    for(short id = 0; id <= last; ++id) {

        std::cout<<arr[id]<<"  ";
    }
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

    std::cout<<std::endl<<"\tAlgorithm\t:\t";
    for(short k = 0; k < size; ++k) {
        std::cout<<arr[k]<<"  ";
    }

    for(int i = 0; i < size - 1; i++) {

        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {

                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }

            std::cout<<std::endl<<"\tStep-"<<i+1<<":"<<j+1<<"\t:\t";
            for(int k = 0; k < size; ++k)
                std::cout<<arr[k]<<"  ";
        }

        if(!swapped)
            break;
        std::cout<<std::endl;
    }
}

void selectionSort(int arr[], short size)
{
    std::cout<<std::endl<<"\tAlgorithm\t:\t";

    for(int i = 0; i < size - 1; i++) {

        int minIndex = i;

        for(int j = i + 1; j < size; j++) {

            if(arr[j] < arr[minIndex])
                minIndex = j;
        }

        std::swap(arr[i], arr[minIndex]);
        std::cout<<arr[i]<<"  ";
    }
}

void insertionSort(int arr[], short size) {

    for(int i = 1; i < size; i++) {

        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
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