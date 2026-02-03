#include <iostream> 
#include <fcntl.h> 
#include <unistd.h> 
#include <cstring>

using namespace std;

int main()
{
	int fd;
	char buffer[100];
	
	//OPEN FILE
	
	fd = open("info.txt",O_CREAT | O_RDWR,0644);
	
	if(fd==-1)
	{
		cout<<"File open failed"<<endl;
		return 1;
	}
	
	//WRITE DATA
	
	char msg[]="Linux file system calls";
	
	write(fd,msg,strlen(msg));
	
	cout<<"Data written"<<endl;
	
	//REPOSITION FILE POINTER TO START
	
	lseek(fd,0,SEEK_SET);
	
	//READ DATA 
	read(fd,buffer,sizeof(buffer));
	
	cout<<"Data read:"<<buffer<<endl;
	
	close(fd);
	
	return 0;
	
}
