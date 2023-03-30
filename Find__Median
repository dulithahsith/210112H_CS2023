#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Median(vector<int> arr) {
    
    vector<int> temp_arr;
    
    for (int i = 0; i < arr.size(); i++) {
        
        temp_arr.push_back(arr[i]);
        insertionSort(temp_arr);
        int mid = temp_arr.size()/2;
        double median;
        if (temp_arr.size() % 2 == 0) {
            median = (temp_arr[mid-1] + temp_arr[mid]) / 2.0;
        } else {
            median = temp_arr[mid];
        }
        cout << fixed << setprecision(1) << median << endl;
    }
}

int main() {
    vector<int> arr = {7, 3, 5, 2};
    cout<<"Input elements: ";
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    Median(arr);
    return 0;
}
