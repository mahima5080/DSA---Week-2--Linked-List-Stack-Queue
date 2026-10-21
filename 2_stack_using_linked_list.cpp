#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() { top = nullptr; }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "✅ Pushed: " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "❌ Stack Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "🗑️ Popped: " << temp->data << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack (Top to Bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~StackLinkedList() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    StackLinkedList stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();
    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    return 0;
}
