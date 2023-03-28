#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

void RecursiveQuickSort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    // partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // recursion
    if (left < j)
        RecursiveQuickSort(arr, left, j);
    if (i < right)
        RecursiveQuickSort(arr, i, right);
}

//////////////////////////////////////////////////////////////////////////


void iterativeQuickSort(vector<int>& arr, int left, int right) {
    int stack[right - left + 1];
    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while (top >= 0) {
        int end = stack[top--];
        int start = stack[top--];

        int i = start, j = end;
        int tmp;
        int pivot = arr[(start + end) / 2];

        // partition
        while (i <= j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        }

        // push left subarray to stack
        if (start < j) {
            stack[++top] = start;
            stack[++top] = j;
        }

        // push right subarray to stack
        if (i < end) {
            stack[++top] = i;
            stack[++top] = end;
        }
    }
}

int main() {
    vector<int> arr_size = {100,500,1000,2000,5000,7500,10000,15000,17500,20000};
    for (int i = 0;i<10; i++){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, arr_size[i]);
    // create vector of arr_size random integers
        vector<int> arr(arr_size[i]);
        for (int i = 0; i < arr_size[i]; i++) {
            arr[i] = dist(gen);
        }
    
    
    
        // measure execution time of recursive Merge Sort
        auto start_recursive = chrono::high_resolution_clock::now();
        RecursiveQuickSort(arr, 0, arr.size() - 1);
        auto end_recursive = chrono::high_resolution_clock::now();
        auto elapsed_recursive = chrono::duration_cast<chrono::microseconds>(end_recursive - start_recursive);
        cout << "Array Size: "<<arr_size[i]<< "   Recursive Quick Sort took " << elapsed_recursive.count() << " microseconds" << endl;
        
        
        
        
        // measure execution time of iterative Merge Sort
        auto start_iterative = chrono::high_resolution_clock::now();
        iterativeQuickSort(arr, 0, arr.size() - 1);
        auto end_iterative = chrono::high_resolution_clock::now();
        auto elapsed_iterative = chrono::duration_cast<chrono::microseconds>(end_iterative - start_iterative);
        cout << "Array Size: "<<arr_size[i]<< "   Iterative Quick Sort took " << elapsed_iterative.count() << " microseconds" << endl;
        cout << ""<<endl;
    }
    
    
    return 0;
}
