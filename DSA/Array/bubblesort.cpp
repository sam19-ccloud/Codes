#include<iostream>
using namespace std;

void print(int a[], int n){    
    int i;    
    for(i = 0; i < n; i++){      
        cout << a[i] << " ";       
    }          
}

void bubble(int a[], int n){    
    int i, j, temp; 
    bool isSwapped;
    for(i = 0; i < n; i++){     
        isSwapped = false;  
        for(j = 0; j < n - i - 1; j++){      
            if(a[j] > a[j + 1]){     
                isSwapped = true;  
                temp = a[j];      
                a[j] = a[j + 1];      
                a[j + 1] = temp;    
            }  
        } 
        if(!isSwapped) {  
            break;  
        }  
    }       
}

int main() {      
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n; 
    int a[n]; 
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {

        cin>>a[i]; 
    }

    cout << "\nBefore sorting array elements are: " << endl;    
    print(a, n); 
    
    bubble(a, n);
    
    cout << "sorting array elements are: " << endl;      
    print(a, n);    
}
