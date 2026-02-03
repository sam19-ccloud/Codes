#include <iostream>
#include <cstdlib> //exit(), abort()

using namespace std;

int main()
{
	int choice;
	
	cout <<"Enter 1 to Exit, 2 to abort: ";
	cin>>choice;
	
	if (choice==1)
	{
		cout<<"process ended normally"<<endl;
		
		//Normal termination
		exit(0);
	}
	
	else
	{
		cout<<"Process aborted abnormaly"<<endl;
		
		//Abnormal termination
		abort();
	}
	
	cout<<"THis line will not execute"<<endl;
	
	return 0;
}
	
