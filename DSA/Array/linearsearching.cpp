#include<iostream>
using namespace std;

    int findkey(){
        int i ;
        int arr[5]={12,23,34,45,56};
    int k =34;
    for (i=0;i<5;i++)
        if (arr[i]==k){return i ;}
        return -1 ;
}

int main(){
 int ans = findkey();
  if (ans==-1){
    cout<<"Element not found ";
    
  }
  else{
    cout<<"Element fount at "<<ans;

  }
}
