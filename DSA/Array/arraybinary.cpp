#include<iostream>
using namespace std;

int binarySearch(int a[], int beg, int end, int k) {
    if (beg < end) {
        int mid = (beg + end) / 2;

        if (a[mid] == k)
            return mid;  
        else if (a[mid] < k)
            return binarySearch(a, mid+1, end, k); 
        else
            return binarySearch(a, beg,mid-1, k); 
        }
        return -1;
}

int main() {
    int a[] = {12, 23, 34, 45, 56, 67, 78, 89};
    int k = 45;
    int n = sizeof(a) / sizeof(a[0]);

    int ans = binarySearch(a, 0,n-1, k);
    if (ans ==-1)
        cout << "Element not found : " << endl;
    else
        cout << "Element found at index: " <<ans<<endl;

}