#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;
int main() { 
	int fd;           
	char buffer[50]; 
	fd = open("demo.txt",O_RDONLY); 
	 int n = read(fd, buffer, sizeof(buffer));
	read(fd, buffer, 20); 
	write(1, buffer, 20); 
	close(fd); 
	return 0;
} 
