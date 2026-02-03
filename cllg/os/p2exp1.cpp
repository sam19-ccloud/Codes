#include <iostream> 
#include <fcntl.h> 
#include <unistd.h> 

using namespace std;

int main()
{
	int fd;
	
	//OPEN FILE IN READ MODE
	
	fd=open("student.txt",O_RDONLY);
	
	if(fd==-1)
	{
		cout<<"File cannot open"<<endl;
		return 1;
	}
	
	cout<<"File opened successfully"<<endl;
	
	//CLOSE FILE
	
	close(fd);
	
	cout<<"File closed successfully"<<endl;
	
	return 0;
	
}
