#include <iostream> 
#include <unistd.h> //exec1

using namespace std;

int main()
{
	cout<<"before exec"<<endl;
	
	//LOAD NEW PROGRAM (ls command)
	execl("/bin/ls","ls","-l",NULL);
	
	cout<<"After exec (not executed)"<<endl;
	
	return 0;
}
