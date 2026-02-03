#include <iostream> 
#include <fcntl.h> 
#include <unistd.h> 

using namespace std;

int main()
{
	int fd;
	
	//CREATE FILE
	
	fd= open("data.txt",O_CREAT | O_WRONLY, 0644);
	
	if(fd == -1)
	{
		cout<<"File creation failed"<<endl;
		return 1;
	}
	
	cout<<"File created successfully"<<endl;
	
	
	//CLOSE FILE
	
	close(fd);
	
	//DELETE FILE
	
	int status = unlink("data.txt");
	
	if(status==0)
		cout<<"File deleted successfully"<<endl;
	else
		cout<<"File deletion failed"<<endl;
		
	return 0;
	
}
