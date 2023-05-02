#include <iostream>
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

   int heap_arr[] = {5,67,23,12,43,51,1,3002,400,33};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}