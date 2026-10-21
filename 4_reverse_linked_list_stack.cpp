#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void reverseUsingStack() {
        if (!head || !head->next) return;

        stack<Node*> st;
        Node* temp = head;

        // Push all nodes onto the stack
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->next;
        }

        // Set head to top node
        head = st.top();
        st.pop();
        temp = head;

        // Pop remaining nodes and re-link pointers
        while (!st.empty()) {
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original List: ";
    list.display();

    list.reverseUsingStack();

    cout << "Reversed List (using Stack): ";
    list.display();

    return 0;
}
