#include <iostream>
#include <chrono>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* arr;
public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        }
        else {
            arr[++top] = x;
        }
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            top--;
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == size - 1);
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else {
            return arr[top];
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack_1(100);

    auto start_stack_array = chrono::high_resolution_clock::now();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    stack_1.push(8);
    stack_1.push(10);
    stack_1.push(5);
    stack_1.push(11);
    stack_1.push(15);
    stack_1.push(23);
    stack_1.push(6);
    stack_1.push(18);
    stack_1.push(20);
    stack_1.push(17);
    stack_1.display();
    for (int i = 0; i < 5 ; i++){
        stack_1.pop();
    }
    stack_1.display();
    stack_1.push(4);
    stack_1.push(30);
    stack_1.push(3);
    stack_1.push(1);
    stack_1.display();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    auto end_stack_array = chrono::high_resolution_clock::now();
    auto elapsed_stack_array = chrono::duration_cast<chrono::microseconds>(end_stack_array - start_stack_array);
    cout <<"Time taken for executing operations of  stack implemented by using array: " << elapsed_stack_array.count() << " microseconds" << endl;

    return 0;
}
