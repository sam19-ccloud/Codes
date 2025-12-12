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
