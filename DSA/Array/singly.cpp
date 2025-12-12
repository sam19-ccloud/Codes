#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function declarations
void insertBegin();
void insertLast();
void insertRandom();
void deleteBegin();
void deleteLast();
void deleteRandom();
void searchElement();
void displayList();

int main() {
    int choice = 0;

    while (choice != 9) {
        cout << "\n\n********* MAIN MENU *********\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at Last\n";
