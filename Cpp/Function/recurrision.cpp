#include<iostream>
using namespace std;
int n; 
int fact(int n){

if (n==0){
    return 1;
}
else if(n==1){
    return 1;
}
else{
    return n*fact(n-1);
}

}

int main(){
    cout<<"Enter value of n  "<<endl;
    cin>>n;
int ans=fact(n);
    cout<<"Factorical of "<<n<<" is "<<ans<<endl;

}