#include<iostream>
using namespace std;
int marks ;


int grade(int marks){
    if (marks>=90){
        cout<<" passed with A grade"<<endl;
        return 0; 
}
    else if (marks>=85){
        cout<<" passed with B grade"<<endl;
        return 0; 
 }
    else if (marks>=75){
        cout<<" passed with C grade"<<endl;
        return 0; 
}
    else if (marks>=55){
        cout<<" passed with D grade"<<endl;
        return 0; 
}
     else if (marks>=45){
        cout<<" passed with E grade"<<endl;
        return 0; 
}
    else{
        cout<<"FAILED"<<endl;}
        return -1;
    }


int main(){
    int i=0;
    int n;
    cout<<"Enter number of students"<<endl;
    cin>>n;
    int marks[n];
    for(i=0;i<=n;i++){
        cout<<"Enter your marks:"<<endl;
        cin>>marks[i];
    }
    for(i=0;i<=n;i++)
    {   cout<<"Status of Student "<<i<<" is : ";
        grade(marks[i]);
    }
}


