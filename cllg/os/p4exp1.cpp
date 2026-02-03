#include <iostream> 
#include <sys/stat.h> //stat(),chmod()
#include <ctime> //time functions

using namespace std;

int main()
{
	struct stat fileInfo;
	
	//GET FILE ATTRIBUTES
	
	if(stat("info.txt",&fileInfo)==0)
	{
		cout<<"file size:"<<fileInfo.st_size<<"bytes"<<endl;
		cout<<"last modified:"<<ctime(&fileInfo.st_mtime);
		cout<<"permissions:"<<fileInfo.st_mode<<endl;
	}
	
	else
	{
		cout<<"cannot get file info"<<endl;
		return 1;
	}
	
	//SET FILE ATTRIBUTES 
	
	//Change permission to rw-r--r--
	chmod("info.txt",0644);
	
	cout<<"file permission changed"<<endl;
	
	return 0;
	
}
