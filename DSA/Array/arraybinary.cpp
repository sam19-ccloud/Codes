#include<iostream>
using namespace std;

int binarySerach(int a[], int beg ,int end,int mid ,int k )
{
int mid;
    if (end > beg);
    mid= (beg+end) /2;
    {
        if(a[mid]==k )    
        {                 
            return mid+1;    
        } 
        else if (a[mid]<k)
        {  
            return binarySerach(a,mid+1, end, k);    
        }
        else     
        {  
            return binarySerach(a,mid-1,beg ,k);    
        }          
    }   
    return -1;
}

int main(){
    int a[]={12,23,34,45,56,67,78,89};
    int k=45;

}