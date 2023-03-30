#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include<vector>

using namespace std;

void quickSort(long arr[], int l, int r) {
    int i = l;
    int j = r;
    int pivot = arr[(l + r) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (l < j) {
        quickSort(arr, l, j);
    }
    if (i < r) {
        quickSort(arr, i, r);
    }
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    srand(time(NULL)); // initialize the random seed
    const int SIZE = 15000;
    long arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand();
    }
    quickSort(arr, 0, SIZE - 1);
    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Execution time: " << duration << " microseconds" << std::endl;
    return 0;
}
