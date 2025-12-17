#include <iostream>  
  
class Node {  
public:  
    int data;  
    Node* next;  
  
    Node(int val) : data(val), next(nullptr) {}  
};  
  
class CircularSinglyLinkedList {  
private:  
    Node* last; // Pointer to the last node. last->next is the head.  
  
public:  
    CircularSinglyLinkedList() : last(nullptr) {}  
  
    // Destructor to free memory  
    ~CircularSinglyLinkedList() {  
        if (last == nullptr) return;  
  
        Node* current = last->next; // Start from head  
        Node* head = last->next;  
        Node* next_node = nullptr;  
  
        // Traverse and delete all nodes  
        do {  
            next_node = current->next;  
            delete current;  
            current = next_node;  
        } while (current != head);  
  
        last = nullptr;  
    }  
  
    // Check if the list is empty  
    bool isEmpty() const {  
        return last == nullptr;  
    }  
  
    // --- Traversal Operation ---  
    // Display the list elements  
    void display(const std::string& prefix = "") const {  
        std::cout << prefix;  
        if (isEmpty()) {  
            std::cout << "List is empty.\n";  
            return;  
        }  
  
        Node* p = last->next; // Start from head  
        std::cout << "Circular Linked List: ";  
        do {  
            std::cout << p->data;  
            p = p->next;  
            if (p != last->next) {  
                std::cout << " -> ";  
            }  
        } while (p != last->next); // Continue until we circle back to the head  
        std::cout << " (circles back to " << last->next->data << ")\n";  
    }  
  
    // --- Insertion Operations ---  
  
    // Helper: Insert into an empty list  
    void insertInEmpty(int data) {  
        Node* newNode = new Node(data);  
        last = newNode;  
        newNode->next = newNode; // Points to itself  
    }  
  
    // 1. Insert at the beginning (before head)  
    void insertAtBeginning(int data) {  
        if (isEmpty()) {  
            insertInEmpty(data);  
            return;  
        }  
  
        Node* newNode = new Node(data);  
        newNode->next = last->next; // New node points to the current head  
        last->next = newNode;      // Last node points to the new node  
    }  
  
    // 2. Insert at the end (after last)  
    void insertAtEnd(int data) {  
        if (isEmpty()) {  
            insertInEmpty(data);  
            return;  
        }  
  
        Node* newNode = new Node(data);  
        newNode->next = last->next; // New node points to the current head  
        last->next = newNode;      // Current last node points to the new node  
        last = newNode;            // Update 'last' to the new node  
    }  
      
    // For the specific output, we also need an insert that can go in the middle.  
    void insertAfter(int existing_data, int new_data) {  
        if (isEmpty()) return;  
  
        Node* p = last->next; // Start from head  
        do {  
            if (p->data == existing_data) {  
                Node* newNode = new Node(new_data);  
                newNode->next = p->next;  
                p->next = newNode;  
                if (p == last) last = newNode; // Update last if insertion is after last node  
                return;  
            }  
            p = p->next;  
        } while (p != last->next);   
    }  
  
    // --- Deletion Operations ---  
  
    // 1. Delete the first node (head)  
    void deleteFromBeginning() {  
        if (isEmpty()) {  
            std::cout << "List is empty. Cannot delete.\n";  
            return;  
        }  
  
        Node* head = last->next;  
  
        if (head == last) { // Only one node in the list  
            delete head;  
            last = nullptr;  
            return;  
        }  
  
        last->next = head->next; // Last node points to the new head (second node)  
        delete head;  
    }  
  
    // 2. Delete the last node  
    void deleteFromEnd() {  
        if (isEmpty()) {  
            std::cout << "List is empty. Cannot delete.\n";  
            return;  
        }  
  
        Node* head = last->next;  
  
        if (head == last) { // Only one node  
            delete head;  
            last = nullptr;  
            return;  
        }  
  
        // Traverse to find the second-to-last node  
        Node* p = head;  
        while (p->next != last) {  
            p = p->next;  
        }  
  
        p->next = head; // Second-to-last node becomes the new last node, pointing to head  
        delete last;  
        last = p; // Update 'last' pointer  
    }  
      
    // 3. Delete a node with a specific value  
    void deleteNode(int value) {  
        if (isEmpty()) return; // Already handled in main for the required output  
  
        Node* head = last->next;  
        Node* current = head;  
        Node* prev = nullptr;  
  
        // Traverse to find the node and its previous node  
        do {  
            if (current->data == value) {  
                break; // Found the node  
            }  
            prev = current;  
            current = current->next;  
        } while (current != head);  
  
        // If node not found, do nothing (for required output)  
        if (current->data != value) return;  
  
        // Deleting the only node  
        if (current == head && current == last) {  
            delete current;  
            last = nullptr;  
            return;  
        }  
  
        // Deleting the head node  
        if (current == head) {  
            last->next = head->next;  
            delete head;  
            return;  
        }  
  
        // Deleting the last node  
        if (current == last) {  
            prev->next = head;  
            delete last;  
            last = prev;  
            return;  
        }  
  
        // Deleting a node in between  
        prev->next = current->next;  
        delete current;  
    }  
  
};  
  
// --- Main function to replicate the exact output ---  
int main() {  
    CircularSinglyLinkedList list;  
  
    // Output Header  
    std::cout << "Insertion Operations \n";  
      
    // Insertion Sequence  
    list.insertAtBeginning(10); // [10]  
    list.display();  
  
    list.insertAtEnd(30);       // [10 -> 30]  
    list.display();  
  
    // To get the output [5 -> 10 -> 30], we need to insert 5 at the beginning  
    list.insertAtBeginning(5);  // [5 -> 10 -> 30]  
    list.display();  
  
    list.insertAtEnd(40);       // [5 -> 10 -> 30 -> 40]  
    list.display();  
      
    // To match the Deletion setup, we must insert 50 before the next block  
    list.insertAtEnd(50);       // [5 -> 10 -> 30 -> 40 -> 50]  
  
    std::cout << "\nDeletion Operations \n";  
  
    // Deletion Sequence  
      
    // 1. Delete first (5) -> [10 -> 30 -> 40 -> 50]  
    list.deleteFromBeginning();   
    list.display("After deleting first: ");  
  
    // 2. Delete last (50) -> [10 -> 30 -> 40]  
    list.deleteFromEnd();         
    list.display("After deleting last: ");  
  
    // 3. Delete 10 (new head) -> [30 -> 40]  
    list.deleteNode(10);   
    list.display("After deleting 10 (new head): ");  
  
    // 4. Delete 40 (new last) -> [30]  
    list.deleteNode(40);          
    list.display("After deleting 40 (new last): ");  
      
    // 5. Delete 30 (empty list) -> []  
    list.deleteNode(30);          
    list.display("After deleting 30 (empty list): ");  
  
    // 6. Try deleting from empty list  
    list.deleteFromBeginning();   
      
    return 0;  
}  