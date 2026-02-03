#include <iostream>
#include <unistd.h>
#include <cstdlib> 

using namespace std;

int main()
{
	pid_t pid;
	
	//CREATE CHILD
	pid=fork();
	
	if (pid==0)
	{
		cout<<"child process running"<<endl;
		
		//terminate child
		exit(0);
	}
	
	else
	{
		cout<<"Parent process running"<<endl;
		
	}
	
	return 0;
}
	
