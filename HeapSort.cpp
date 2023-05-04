#include <iostream>
#include<vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int l=2*root+1;
    int r=2*root+2;
    int largest=root;
    if (arr[l]>arr[root]&&(l<n)){
        largest=l;
    }
    if(arr[r]>arr[largest]&&(r<n)){
        largest=r;
    }
    if(largest!=root){
        swap(arr[root],arr[largest]);
        heapify(arr,n,largest);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
    // extracting elements from heap one by one
   for(int j=n-1;j>=1;j--){
        swap(arr[0],arr[j]);
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
int main() {
    vector<int> temp_arr;
    int num;
    cout<<"Type -1 after inputting elements"<<endl;
    while(1>0){
        cout<<"Input element: ";
        cin>>num;
        if(num==-1){
            break;}
        temp_arr.push_back(num);
    }
    int n=temp_arr.size();
    int heap_arr[n];
    for(int i=0;i<n;i++){
        heap_arr[i]=temp_arr[i];
    }
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
    heapSort(heap_arr,n);
    cout<<"Sorted array"<<endl;
    displayArray(heap_arr,n);
    return 0;
}
