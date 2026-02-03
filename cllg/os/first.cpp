#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std; 
int main() { 
	int fd; 
	fd = open("demo.txt", O_CREAT | O_WRONLY, 0644); 
	write(fd, "OS Learning Made Easy", 20);
	close(fd); 
cout << "File created successfully" << endl; 
return 0; 

} 
