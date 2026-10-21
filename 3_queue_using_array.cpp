#include <iostream>
using namespace std;

#define MAX_SIZE 100

class QueueArray {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    QueueArray() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "❌ Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        arr[rear] = val;
        cout << "✅ Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "❌ Queue Underflow!" << endl;
            return;
        }
        cout << "🗑️ Dequeued: " << arr[front] << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue (Front to Rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    QueueArray q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
