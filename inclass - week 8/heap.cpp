#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left_index = (root * 2) + 1;
   int right_index = (root * 2) + 2;
   int largest_index = root;

   if (left_index < n && arr[left_index] > arr[largest_index]){
      largest_index = left_index;
   }
   if (right_index < n && arr[right_index] > arr[largest_index]){
      largest_index = right_index;
   }
   if (largest_index != root){
      int temp = arr[root];
      arr[root] = arr[largest_index];
      arr[largest_index] = temp;
      heapify(arr,n,largest_index);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2-1 ; i >= 0 ; i--){
      heapify(arr,n,i);
   }
   // extracting elements from heap one by one
   for ( int j = n -1 ; j >= 0 ; j-- ){
      int temp = arr[0];
      arr[0] = arr[j];
      arr[j] = temp;
      heapify(arr,j,0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   srand(time(0));
   int size_arr;
   cout<<"Enter the size Of the array :";
   cin >> size_arr;
   
   int heap_arr[size_arr];

   for (int i = 0; i < size_arr; i++) {
        heap_arr[i] = rand() % 3000 + 1; 
    }

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}