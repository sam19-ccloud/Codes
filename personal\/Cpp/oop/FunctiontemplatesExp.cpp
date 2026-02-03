#include<iostream>

using namespace std;

template <typename A>

A add(A a,A b){
    return a+b;
}

template <typename A>

A sub(A a,A b){
    return a-b;
} 

int main(){
cout<<add(4,5);
cout<<sub<float>(4.4,5.4);
}
