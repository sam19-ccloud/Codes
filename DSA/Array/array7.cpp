#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter a number to guess the hidden Number ";
    cin>>num;
    switch(num){
        case 10:cout<<"...you guessed right! 10 was a hidden number...";break;
        case 20:cout<<"...you guessed right! 20 was a hidden number...";break;
        case 30:cout<<"...you guessed right! 30 was a hidden number...";break;
        default:cout<<"...you guessed wrong...";break;
    }
}