#include <iostream> 
#include <fcntl.h> 
#include <unistd.h> 
using namespace std; 
int main(){ 
	int fd; 
	fd=open("practice.txt",O_CREAT|O_WRONLY,0644); 
	write(fd, "have a nice day", 16); 
	close(fd); 
	cout<<"File created successfully"<<endl; 
	return 0; 
} 
