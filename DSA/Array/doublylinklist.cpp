#include <iostream>  
#include <string>  
#include <sstream>  
using namespace std;  
//  Node Structure/Class  
class Node {  
public:  
    int data;  
    Node* next;  
    Node* prev;  
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}  
};  
//  Doubly Linked List Class  
class DoublyLinkedList {  
private:  
    Node* head;  
    Node* tail;  
    // Helper to print operation status  
    // FIX: Added 'const' here because this function does not modify the list object.  
    void printOperation(const string& op, int data, int pos, const string& msg) const {   
        cout << "Operation: " << op;  
        if (data != 0) {  
            cout << ": " << data;  
        }  
        if (pos >= 0) {  
            cout << " at position " << pos;  
        }  
        if (!msg.empty()) {  
            cout << " (" << msg << ")";  
        }  
        cout << endl;  
    }  
public:  
    // Constructor (Initializes list)  
    DoublyLinkedList() : head(nullptr), tail(nullptr) {  
        cout << "DoublyLinkedList Initialized." << endl;  
    }  
    // Destructor (Frees all nodes/memory)  
    ~DoublyLinkedList() {  
        destroyList();  
        cout << "\nMemory cleanup complete (Destructor called)." << endl;  
    }  
    //  Doubly Linked List Operations  
    // Inserting at head  
    void insertAtHead(int data) {  
        Node* newNode = new Node(data);  
        if (head == nullptr) {  
            head = newNode;  
            tail = newNode;  
        } else {  
            newNode->next = head;  
            head->prev = newNode;  
            head = newNode;  
        }  
        printOperation("Inserting at head", data, -1, "");  
    }  
    // Inserting at end  
    void insertAtEnd(int data) {  
        Node* newNode = new Node(data);  
        if (head == nullptr) {  
            head = newNode;  
            tail = newNode;  
            printOperation("Inserting at end", data, -1, "list was empty");  
            return;  
        }  
        tail->next = newNode;  
        newNode->prev = tail;  
        tail = newNode;  
        printOperation("Inserting at end", data, -1, "");  
    }  
    // Inserting at position  
    void insertAtPosition(int data, int position) {  
        if (position < 0) {  
            cout << "Invalid position: " << position << ". Position must be 0 or greater." << endl;  
            return;  
        }  
        if (position == 0) {  
            insertAtHead(data);  
            return;  
        }  
        if (head == nullptr) {  
            cout << "Position " << position << " is beyond the list size. Cannot insert " << data << "." << endl;  
            return;  
        }  
        Node* current = head;  
        int i = 0;  
        // Traverse to the node *before* the desired position  
        while (current != nullptr && i < position - 1) {  
            current = current->next;  
            i++;  
        }  
        if (current == nullptr) {  
            cout << "Position " << position << " is beyond the list size. Cannot insert " << data << "." << endl;  
            return;  
        }  
        // If current->next is null, we are at the last node, so append  
        if (current->next == nullptr) {  
            insertAtEnd(data);  
            return;  
        }  
        // General insertion logic  
        Node* newNode = new Node(data);  
        newNode->next = current->next;  
        newNode->prev = current;  
        current->next->prev = newNode;  
        current->next = newNode;  
        printOperation("Inserting", data, position, "");  
    }  
    // Delete at head  
    void deleteHead() {  
        if (head == nullptr) {  
            printOperation("Delete the head node", 0, -1, "List is empty. Cannot delete head.");  
            return;  
        }  
        Node* temp = head;  
        int deletedData = temp->data;  
        if (head == tail) { // Only one node  
            head = nullptr;  
            tail = nullptr;  
        } else {  
            head = head->next;  
            head->prev = nullptr;  
        }  
        delete temp;  
        printOperation("Delete the head node", deletedData, -1, "Success");  
    }  
    // Delete at end  
    void deleteTail() {  
        if (head == nullptr) {  
            printOperation("Delete the end node", 0, -1, "List is empty. Cannot delete tail.");  
            return;  
        }  
        Node* temp = tail;  
        int deletedData = temp->data;  
        if (head == tail) { // Only one node  
            head = nullptr;  
            tail = nullptr;  
        } else {  
            tail = tail->prev;  
            tail->next = nullptr;  
        }  
        delete temp;  
        printOperation("Delete the end node", deletedData, -1, "Success");  
    }  
    // Delete by value  
    void deleteByValue(int key) {  
        Node* current = head;  
        // Search for the key  
        while (current != nullptr && current->data != key) {  
            current = current->next;  
        }  
        if (current == nullptr) {  
            printOperation("Delete by value", key, -1, "Value not found. Cannot delete.");  
            return;  
        }  
        // Adjust prev node's next pointer  
        if (current->prev != nullptr) {  
            current->prev->next = current->next;  
        } else { // Deleting the head node  
            head = current->next;  
        }  
        // Adjust next node's prev pointer  
        if (current->next != nullptr) {  
            current->next->prev = current->prev;  
        } else { // Deleting the tail node  
            tail = current->prev;  
        }  
        delete current;  
        printOperation("Delete by value", key, -1, "Success");  
    }  
    // Traversing the linked list (Forward)  
    // FIX: Already had 'const', which is correct.  
    void traverse() const {  
        Node* current = head;  
        cout << "List state (Forward): ";  
        if (current == nullptr) {  
            cout << "Empty" << endl;  
            return;  
        }  
        while (current != nullptr) {  
            cout << current->data;  
            current = current->next;  
            if (current != nullptr) {  
                cout << " <-> ";  
            }  
        }  
        cout << endl;  
    }  
    // Traversing the linked list (Reverse)  
    // FIX: Already had 'const', which is correct.  
    void traverseReverse() const {  
        Node* current = tail;  
        cout << "List state (Reverse): ";  
        if (current == nullptr) {  
            cout << "Empty" << endl;  
            return;  
        }  
        while (current != nullptr) {  
            cout << current->data;  
            current = current->prev;  
            if (current != nullptr) {  
                cout << " <-> ";  
            }  
        }  
        cout << endl;  
    }  
    // Search by value  
    // FIX: Already had 'const', which is correct.  
    bool search(int key) const {  
        Node* current = head;  
        while (current != nullptr) {  
            if (current->data == key) {  
                // Now this call is valid because printOperation is also const  
                printOperation("Search by value", key, -1, "Found");   
                return true;  
            }  
            current = current->next;  
        }  
        // Now this call is valid because printOperation is also const  
        printOperation("Search by value", key, -1, "Not Found");  
        return false;  
    }  
    // Cleanup function (called by destructor)  
    void destroyList() {  
        Node* current = head;  
        Node* next;  
        while (current != nullptr) {  
            next = current->next;  
            delete current;  
            current = next;  
        }  
        head = nullptr;  
        tail = nullptr;  
    }  
};  
int main() {  
    cout << "Executing Doubly Linked List Operations\n";  
    DoublyLinkedList listOps;  
    listOps.traverse();  
    //Insertion Operations  
    cout << "\nInsertion Phase\n";  
    listOps.insertAtHead(5);  
    listOps.insertAtHead(1);  
    listOps.insertAtEnd(10);  
    listOps.insertAtPosition(7, 2);   
    //Traversal and Search  
    cout << "\nTraversal and Search Phase\n";  
    listOps.search(10);  
    listOps.search(99);   
    //Deletion Operations  
    cout << "\nDeletion Phase\n";  
    listOps.deleteHead();   
    listOps.traverse();  
    listOps.deleteTail();   
    listOps.traverse();  
    listOps.deleteByValue(7);   
    listOps.traverse();  
    // Delete remaining element (5)  
    listOps.deleteHead();  
    listOps.traverse();  
    // Attempt to delete from an empty list  
    listOps.deleteHead();  
    return 0;  
}  