#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}


void display() {
    Node* temp = top;
    cout << "Stack elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();


    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);

    display();

    for(int i = 0; i < 5; i++) {
        pop();
    }

    display();

    push(4);
    push(30);
    push(3);
    push(1);

    display();

    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Execution time: " << duration << " microseconds" << std::endl;

    return 0;
}
