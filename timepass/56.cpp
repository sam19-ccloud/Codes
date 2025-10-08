#include<iostream>
using namespace std;

void createArray(int *&arr, int &size) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }

    cout << "Enter Size: ";
    cin >> size;

    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter Element No." << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Array created successfully...\n";
}

void displayArray(int *arr, int size) {
    if (arr == nullptr || size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array Elements:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int *&arr, int &size) {
    if (arr == nullptr || size == 0) {
        cout << "Array is empty. Please create it first.\n";
        return;
    }

    int pos, val;
    cout << "Enter position to insert (0 to " << size << "): ";
    cin >> pos;
    if (pos < 0 || pos > size) {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter value to insert: ";
    cin >> val;

    int *newArr = new int[size + 1];

    for (int i = 0; i < pos; i++)
        newArr[i] = arr[i];

    newArr[pos] = val;

    for (int i = pos; i < size; i++)
        newArr[i + 1] = arr[i];

    delete[] arr;
    arr = newArr;
    size++;

    cout << "Element inserted successfully.\n";
}
void deleteElement(int *&arr, int &size) {
    if (arr == nullptr || size == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }

    int pos;
    cout << "Enter position to delete (0 to " << size - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= size) {
        cout << "Invalid position.\n";
        return;
    }

    int *newArr = new int[size - 1];

    for (int i = 0; i < pos; i++)
        newArr[i] = arr[i];

    for (int i = pos + 1; i < size; i++)
        newArr[i - 1] = arr[i];

    delete[] arr;
    arr = newArr;
    size--;

    cout << "Element deleted successfully.\n";
}
void searchElement(int *arr, int size) {
    if (arr == nullptr || size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    bool found = false;
    cout << "Found at index(es): ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "Value not found in array.";
    }
    cout << endl;
}
int main() {
    int *p = nullptr; 
    int size = 0;
    int ch;

    while (true) {
        cout << "\nEnter Operation from following:\n"
             << "1) Create an Array\n"
             << "2) Display an Array\n"
             << "3) Insert in an Array\n"
             << "4) Delete from an Array\n"
             << "5) Search in Array\n"
             << "6) Exit\n"
             << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                createArray(p, size);
                break;
            case 2:
                displayArray(p, size);
                break;
            case 3:
                insertElement(p, size);
                break;
            case 4:
                deleteElement(p, size);
                break;
            case 5:
                searchElement(p, size);
                break;
            case 6:
                cout << "Exiting program.\n";
                delete[] p; 
                return 0;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}
