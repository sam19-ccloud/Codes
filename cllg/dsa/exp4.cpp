#include<iostream>
#include<cstring>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits

using namespace std;
typedef struct keyword{
	char key[20];
	char meaning[100];
}WORD;
typedef struct node
{
   struct node *LC;
   WORD data;
   int height;
   struct node *RC;
}NODE;
 
class AVL
{
	NODE *root;
	int count;
	public:
	AVL()
	{
		root=NULL;
		count=0;
	}
	  NODE *llrotate(NODE* Pptr)
	{
		NODE *Aptr;
		Aptr = Pptr->LC;
		Pptr->LC = Aptr->RC;
		Aptr->RC = Pptr;
		cout<<"Left-Left Rotation";
		return Aptr;
	}
	
    NODE *rrrotate(NODE* Pptr)
	{
		NODE *Aptr;
		Aptr = Pptr->RC;
		Pptr->RC = Aptr->LC;
		Aptr->LC = Pptr;
		cout<<"Right-Right Rotation";
		return Aptr;
	}

     NODE *lrrotate(NODE* Pptr)
	{
		NODE *Aptr;
		Aptr = Pptr->LC;
		Pptr->LC = rrrotate(Pptr);
		cout<<"Left-Right Rotation";
		return llrotate(Pptr);	
	}
	
	NODE *rlrotate(NODE* Pptr)
	{
		NODE *Aptr;
		Aptr = Pptr->RC;
		Pptr->RC = lrrotate(Pptr);
		cout<<"Right-Left Rotation";
		return rrrotate(Pptr);	
	}
	
	
   
};