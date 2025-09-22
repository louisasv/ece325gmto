#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

//node structure for linked lists

struct Node {
        int data; //data to be stored in the node
        Node* next; // pointer to the next node in the linked list
        Node(int val) : data(val), next(nullptr) {} // constructor to initialize a new node, initializing its next pointer to the null pointer

    };

class StackLL{
    private: 
        Node* top;  // pointer to the top node in the stack

        public:
        //constructor to initialize the stack with an empty linked list
        StackLL() : top(nullptr) {}
        // destructor to deallocate the memory allocated for the linked list when the stack object is destroyed
        ~StackLL() {
            while(!isEmpty()) {
                pop();
            }

        }
        bool isEmpty() {
            return top == nullptr;  // checks if the top pointer is null, if it is then the stack is empty, return true, else false
}
        bool isFull() {
            // A linked list is never full unless the system runs out of memory.
            return false;
        }
        void push(int value) {
            Node* newNode = new Node(value);  // create a new node with the given value
            newNode->next = top;  // link the new node to the current top of the stack
            top = newNode;  // update the top pointer to the new node
            cout << "Pushed " << value << " to stack." << endl;
        }

        int pop() {
            if(isEmpty()){
                return -1;  // if the stack is empty, return -1 to indicate an error
            }
            Node* temp = top;  // store the top node in a temporary variable
            int value = temp->data;  // store the value of the top node in a temporary variable
            top= top->next;  // update the top pointer to the next node in the stack
            delete temp;  // delete the temporary node, this deallocates the memory used by the node
            return value;
        }

        void display() {
            if(isEmpty()){
                cout << "Stack is empty." << endl;
                return;
            }
            cout << "Stack elements: ";
            Node* current = top;  // Start from the top
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };
     class QueueLL{
        private:
        Node* front;  // pointer to the front node in the queue
        Node* rear;  // pointer to the rear node in the queue

        public:
        // constructor to initialize the queue with an empty linked list
        QueueLL() : front(nullptr), rear(nullptr) {} 

        // destructor to deallocate the memory allocated for the linked list when the queue object is destroyed
        ~QueueLL() {
            while(!isEmpty()) {
                dequeue();
            }
        }
        bool isEmpty() {
            return front == nullptr;  // checks if the front pointer is null, if it is then the queue is empty, return true, else false
        }
        bool isFull() {
            // A linked list is never full unless the system runs out of memory.
            return false;
        }
        void enqueue(int value) {
            Node* newNode = new Node(value);  // create a new node with the given value
            if(isEmpty()){
                front = rear = newNode;  // if the queue is empty, both front and rear point to the new node
            }
            else {
                rear->next = newNode;  // if the queue is not empty, link the new node to the current rear node
                rear = newNode;  // update the rear pointer to the new node
            }
            cout << "Enqueued " << value << " to queue." << endl;
        }
        int dequeue() {
            if(isEmpty()){
                return -1;  // if the queue is empty, return -1 to indicate an error
            }
            Node* temp = front;  // store the front node in a temporary variable
            int value = temp->data;  // store the value of the front node in a temporary variable
            front = front->next;  // update the front pointer to the next node in the queue
            if(front == nullptr) {
                rear = nullptr;  // if the queue becomes empty after dequeuing, set the rear pointer to null
            }
 
            delete temp;  // deallocate the temporary node, this deallocates the memory used by the node
            return value;

        }
        void display() {
            if(isEmpty()){
                cout << "Queue is empty." << endl;
                return;
            }
            cout << "Queue elements: ";
            Node* current = front;  // Start from the front
            while(current!= nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    };


class Stack
 {
    private:
          int capacity;  // max capacity of the stack
          int top;      //index of the top element in the stack
          int* arr;   // pointer to dynamic array to store stack elements

    public:
        // Constructor , creating an array and initilizing top to -1 to mark as empty
        //the stack constructor here allocates memory on to the heap for an integer aray using the arr = new int[size], this is performing dynamic memory allocation 

        Stack(int size) {
            capacity = size;
            arr = new int[size];    // allocating memory,'new' to allocate memory from heap, 'int' to determine data type, and [size] to determine the size of the array
            top = -1;
        }
 
        // Destructor , deleting the array , the destructor is called when the object goes out of scope/deleted
        ~Stack() {
            delete[] arr;      // the memory that arr  points to on the heap is no longer needed.
        }

        // Function to check if the stack is full
        bool isFull() {
            return top == capacity - 1;        // checks if the top indeex has reached the last available position on the array, if it has then the stack is full return true, else false 
            // The array index starts from 0, so the last available position is capacity - 1
        }
        // Function to check if the stack is empty
        bool isEmpty(){
            return top == -1;      //checks if the top index is -1 , if it is then it means that hte stack is empty, return true else false
        }

        // Function to add an element to the stack
        void push(int value){
            if(!isFull()){
                arr[++top] = value;  // if the stack is not full, increment the top index and then assign the value of the new element 
                cout << "Pushed " << value << " to stack." << endl;
            
            }
        }
        // Function to remove an element from the stack
        int pop(){
            if(!isEmpty()){
                 int value = arr[top--]; // if the stack is not empty, decrement the top index and then return the value of the top element
                return value;
                // else return -1 to indicate that the stack is empty
                   
            }
            return -1; // Indicates stack was empty
        }
        // Function to get the top element of the stack
        int peek(){
            if(!isEmpty()){
                cout<< "Top element of the stack: "<<arr[top]<<endl;
                return arr[top]; //if the stack is not empty return the value of the top element 
            }
            return -1; // Return a value indicating stack is empty
        }
        // Function to display the stack elements
        void display(){
            if(isEmpty()){
                cout << "Stack is empty." << endl;
                return;
            }
            cout<< "Stack elements: ";
            for(int i=top; i>=0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

class Queue {
private:
    int capacity;
    int* arr;
    int front;
    int rear;
    int count;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int value) {
        if (!isFull()) {
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            count++;
            cout << "Enqueued " << value << " to queue." << endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int value = arr[front];
            front = (front + 1) % capacity;
            count--;
            return value;
        }
        return -1; // Indicates queue was empty
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int j = front;
        for (int i = 0; i < count; i++) {
            cout << arr[j] << " ";
            j = (j + 1) % capacity;
        }
        cout << endl;
    }
};


int main() {
    while (true) { // Main loop to return to the menu
        int choice;
        cout << "Choose implementation type:" << endl;
        cout << "[1] Array" << endl;
        cout << "[2] Linked List" << endl;
        cout << "Enter your choice (or '*' to exit): ";
        
        string initial_input;
        cin >> initial_input;

        if (initial_input == "*") {
            cout << "Exiting program." << endl;
            break;
        }

        try {
            choice = stoi(initial_input);
        } catch (const std::invalid_argument& e) {
            cout << "Invalid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            int size;
            cout << "Enter the size of the array: ";
            cin >> size;
            if (size <= 0) {
                cout << "Size must be positive." << endl;
                continue;
            }
            Stack stack(size);
            Queue queue(size);

            cout << "\nEnter elements to add to stack and queue." << endl;
            cout << "Special characters: '#' (pop multiple), '?' (move), ';' (display and reset), '*' (exit)." << endl;

            string input;
            while (true) {
                cout << "Enter element or special character: ";
                cin >> input;

                if (input == "#") {
                    int m;
                    cout << "Enter the number of elements to remove: ";
                    cin >> m;
                    if (m > 0) {
                        cout << "Stack elements removed: ";
                        for (int i = 0; i < m; ++i) {
                            if (stack.isEmpty()) break;
                            cout << stack.pop() << (i == m - 1 ? "" : ", ");
                        }
                        cout << endl;

                        cout << "Queue elements removed: ";
                        for (int i = 0; i < m; ++i) {
                            if (queue.isEmpty()) break;
                            cout << queue.dequeue() << (i == m - 1 ? "" : ", ");
                        }
                        cout << endl;
                    }
                } else if (input == "?") {
                    int move_choice;
                    cout << "Move element: [1] Queue->Stack or [2] Stack->Queue? ";
                    cin >> move_choice;
                    if (move_choice == 1) { // Move Q -> S
                        if (queue.isEmpty()) {
                            cout << "Queue is empty. Cannot move." << endl;
                        } else if (stack.isFull()) {
                            cout << "Stack is full. Cannot move." << endl;
                        } else {
                            stack.push(queue.dequeue());
                        }
                    } else if (move_choice == 2) { // Move S -> Q
                        if (stack.isEmpty()) {
                            cout << "Stack is empty. Cannot move." << endl;
                        } else if (queue.isFull()) {
                            cout << "Queue is full. Cannot move." << endl;
                        } else {
                            queue.enqueue(stack.pop());
                        }
                    } else {
                        cout << "Invalid move choice." << endl;
                    }
                } else if (input == ";") {
                    cout<<endl;
                    cout << "--- Displaying all elements ---" << endl;
                    cout<<endl;

                    stack.display();
                    queue.display();
                    cout << "--- Clearing structures and returning to main menu ---" << endl<<endl;
                    break; // Exits inner loop, stack/queue are destroyed, main loop continues
                } else if (input == "*") {
                    cout << "Exiting program." << endl;
                    return 0; // Exit program completely
                } else {
                    try {
                        int value = stoi(input);
                        if (stack.isFull() || queue.isFull()) {
                            cout << "A structure is full. Cannot add element." << endl;
                            cout<<endl;

                        } else {
                            stack.push(value);
                            queue.enqueue(value);
                        }
                    } catch (const std::invalid_argument& e) {
                        cout << "Invalid input. Please enter an integer or a special character." << endl;
                    }
                }
            }
        } else if (choice == 2) {
            StackLL stack;
            QueueLL queue;

            cout << "\nEnter elements to add to stack and queue (Linked List)." << endl;
            cout << "Special characters: '#' (pop multiple), '?' (move), ';' (display and reset), '*' (exit)." << endl;

            string input;
            while (true) {
                cout << "Enter element or special character: ";
                cin >> input;

                if (input == "#") {
                    int m;
                    cout << "Enter the number of elements to remove: ";
                    cin >> m;
                    if (m > 0) {
                        cout << "Stack elements removed: ";
                        for (int i = 0; i < m; ++i) {
                            if (stack.isEmpty()) break;
                            cout << stack.pop() << (i == m - 1 ? "" : ", ");
                        }
                        cout << endl;

                        cout << "Queue elements removed: ";
                        for (int i = 0; i < m; ++i) {
                            if (queue.isEmpty()) break;
                            cout << queue.dequeue() << (i == m - 1 ? "" : ", ");
                        }
                        cout << endl;
                    }
                } else if (input == "?") {
                    int move_choice;
                    cout << "Move element: [1] Queue->Stack or [2] Stack->Queue? ";
                    cin >> move_choice;
                    if (move_choice == 1) { // Move Q -> S
                        if (queue.isEmpty()) {
                            cout << "Queue is empty. Cannot move." << endl;
                        } else {
                            stack.push(queue.dequeue());
                        }
                    } else if (move_choice == 2) { // Move S -> Q
                        if (stack.isEmpty()) {
                            cout << "Stack is empty. Cannot move." << endl;
                        } else {
                            queue.enqueue(stack.pop());
                        }
                    } else {
                        cout << "Invalid move choice." << endl;
                    }
                } else if (input == ";") {
                    cout << endl;
                    cout << "--- Displaying all elements ---" << endl;
                    cout << endl;

                    stack.display();
                    queue.display();
                    cout << "--- Clearing structures and returning to main menu ---" << endl << endl;
                    break; // Exits inner loop, stack/queue are destroyed, main loop continues
                } else if (input == "*") {
                    cout << "Exiting program." << endl;
                    return 0; // Exit program completely
                } else {
                    try {
                        int value = stoi(input);
                        stack.push(value);
                        queue.enqueue(value);
                    } catch (const std::invalid_argument& e) {
                        cout << "Invalid input. Please enter an integer or a special character." << endl;
                    }
                }
            }
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    
     
    return 0;
}
