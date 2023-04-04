#include <iostream>
#include <chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    bool isEmpty() {
        return (top == nullptr);
    }
    bool isFull() {
        return false;
    }
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else {
            return top->data;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack_2;

    auto start_stack_linked = chrono::high_resolution_clock::now();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    stack_2.push(8);
    stack_2.push(10);
    stack_2.push(5);
    stack_2.push(11);
    stack_2.push(15);
    stack_2.push(23);
    stack_2.push(6);
    stack_2.push(18);
    stack_2.push(20);
    stack_2.push(17);
    stack_2.display();
    for (int i = 0; i < 5 ; i++){
        stack_2.pop();
    }
    stack_2.display();
    stack_2.push(4);
    stack_2.push(30);
    stack_2.push(3);
    stack_2.push(1);
    stack_2.display();
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    auto end_stack_linked = chrono::high_resolution_clock::now();
    auto elapsed_stack_linked = chrono::duration_cast<chrono::microseconds>(end_stack_linked - start_stack_linked);
    cout <<"Time taken for executing operations of  stack implemented by using linked list: " << elapsed_stack_linked.count() << " microseconds" << endl;


    return 0;
}
