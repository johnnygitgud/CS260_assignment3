#include <iostream>

class Node {
    //THis class inities Nodes for a singly linked list.
public:
    int data;     // Data part
    Node* next;   // Pointer to the next node

    //Below is the constructor method. This will make it easier to create Node Objects
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    //Constructor for the Queue class
private:
    Node* front; // Pointer to the front of the queue
    Node* back;  // Pointer to the back of the queue

public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }

    // Enqueue method
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (back == nullptr) { // If the queue is empty
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Dequeue method
    int dequeue() {
        if (front == nullptr) { // If the queue is empty
            std::cerr << "Queue is empty!" << std::endl;
            return -1; // Indicating an error
        }
        Node* temp = front;
        int dequeuedValue = temp->data;
        front = front->next;
        if (front == nullptr) { // If the queue is now empty
            back = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    // Peek method
    int peek() {
        if (front == nullptr) { // If the queue is empty
            std::cerr << "Queue is empty!" << std::endl;
            return -1; // Indicating an error
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;

    // Test enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Test peek
    std::cout << "Peek: " << q.peek() << std::endl; // Should print 10

    // Test dequeue
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Should print 10
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Should print 20

    // Test isEmpty
    std::cout << "Is Empty: " << q.isEmpty() << std::endl; // Should print 0 (false)

    // Test dequeue on last element
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Should print 30
    std::cout << "Is Empty: " << q.isEmpty() << std::endl; // Should print 1 (true)

    // Test dequeue on empty queue
    std::cout << "Dequeue: " << q.dequeue() << std::endl; // Should print "Queue is empty!" and return -1

    return 0;
}









// #include <iostream>
// //The code below has been commented out. The purpose of the code below was to test out basic pointer sytnax.

// int main() {
//     int value = 10;             // An integer variable
//     int* pointerToValue = &value; // A pointer to an integer, initialized to the address of `value`

//     std::cout << "Value: " << value << std::endl;            // Prints the value (10)
//     std::cout << "Pointer: " << pointerToValue << std::endl; // Prints the address of `value`
//     std::cout << "Dereferenced pointer: " << *pointerToValue << std::endl; // Prints the value pointed to by the pointer (10)

//     return 0;
// }