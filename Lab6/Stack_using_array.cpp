#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

int top = -1;
int* arr;

bool isFull(int size){
    if(top == size-1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if (top == -1){
        return true;
    }
    else{
        return false;
    }
}

void push(int val, int size) {
    if (isFull(size)){
        cout<<"Error-->Stack Overflow!" << endl;
    }
    else{
        top += 1;
        arr[top] = val;
    }
}

int pop() {
    if (isEmpty()) {
        cout <<"Error-->Stack Underflow!" << endl;
        return -1; // return a special value to indicate underflow
    } 
    else {
        int val = arr[top];
        top -= 1;
        return val;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } 
    else {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    
    cout << "Enter the size of the stack: ";
    cin >> size;
    auto start_time = std::chrono::high_resolution_clock::now();
    arr = new int[size];

    push(8, size);
    push(10, size);
    push(5, size);
    push(11, size);
    push(15, size);
    push(23, size);
    push(6, size);
    push(18, size);
    push(20, size);
    push(17, size);

    display();

    for(int i = 0; i < 5; i++) {
        pop();
    }

    display();

    push(4, size);
    push(30, size);
    push(3, size);
    push(1, size);

    display();

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Execution time: " << duration << " microseconds" << std::endl;

    return 0;
}
