 #include<iostream>
using namespace std;

void createArray(int *&arr, int &size) {
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
    if (arr == NULL || size == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array Elements:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

 
int main() {
    int *p = NULL;  
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
            case 6:
                cout << "Exiting program.\n";
                delete[] p;  
                return 0;
            default:
                cout << "Invalid choice or feature not implemented yet.\n";
                break;
        }
    }

    return 0;
}


