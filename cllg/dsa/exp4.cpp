 #include<iostream>
#include<ios> 
#include<limits> 
#include<cstring>
#define MAX 20
using namespace std;

typedef struct Node{
    struct Node *LC;
    string word;
    string meaning;
    struct Node *RC;    
}NODE;

class Stack{
   NODE *stk[MAX];
   int top;
   
   public:
    Stack(){
       top=-1;
    }
   
   void push(NODE * val){
        if(!isFull())
            stk[++top]=val;
        else
            cout<<"\nStack Full!";
   }

    NODE* pop(){
        if(!isEmpty())
            return stk[top--];
        else{
            cout<<"\nStack Empty!";
            return NULL;
        }
    }
    
    bool isFull(){
        return (top==MAX-1);
    }
    
    bool isEmpty(){
        return (top==-1);
    }
};

class BST{
    private:
        NODE *root;
        Stack S;

    public:
        BST(){
            root=NULL;
        }

    void addNode(string word, string meaning){
        NODE *p=new NODE;
        p->LC=NULL;
        p->word=word;
        p->meaning=meaning;
        p->RC=NULL;
        
        if(root==NULL){
            root=p;
        }
        else{
            NODE *cur=root,*f=NULL;
            
            while(cur){
                f=cur;
                if(word == cur->word){
                    cout<<"\nDuplicate node!!";
                    delete p;
                    return;
                }
                else if(word > cur->word)
                    cur=cur->RC;
                else
                    cur=cur->LC;
            }
            if(word > f->word)
                f->RC=p;
            else
                f->LC=p;
        }
    }
    
    
void deleteNode(string key)
{
    NODE *parent=NULL,*cur=root,*p;
    bool found=false;

    if(root==NULL){
        cout<<"\nTree Empty!!";
        return;
    }

    while(cur)
    {
        if(key==cur->word)
        {
            found=true;

            if(cur == root)
            {
                if(cur->LC==NULL && cur->RC==NULL){
                    root=NULL;
                    delete cur;
                }
                else if(cur->LC!=NULL && cur->RC==NULL){
                    root=cur->LC;
                    delete cur;
                }
                else if(cur->LC==NULL && cur->RC!=NULL){
                    root=cur->RC;
                    delete cur;
                }
                else{
                    p=cur->RC;
                    while(p->LC!=NULL)
                        p=p->LC;
                    cur->word=p->word;
                    cur->meaning=p->meaning;
                    deleteNode(p->word);
                }
                return;
            }

            if(cur->LC==NULL && cur->RC==NULL){
                if(parent->LC==cur)
                    parent->LC=NULL;
                else
                    parent->RC=NULL;
                delete cur;
            }
            else if(cur->LC!=NULL && cur->RC==NULL){
                if(parent->LC==cur)
                    parent->LC=cur->LC;
                else
                    parent->RC=cur->LC;
                delete cur;
            }
            else if(cur->LC==NULL && cur->RC!=NULL){
                if(parent->LC==cur)
                    parent->LC=cur->RC;
                else
                    parent->RC=cur->RC;
                delete cur;
            }
            else{
                p=cur->RC;
                while(p->LC!=NULL)
                    p=p->LC;
                cur->word=p->word;
                cur->meaning=p->meaning;
                deleteNode(p->word);
            }
            return;
        }

        parent=cur;
        if(key<cur->word)
            cur=cur->LC;
        else
            cur=cur->RC;
    }

    if(!found)
        cout<<"\nNode not found!!";
}
    
    
    void updateNode(string word){
        
        if(root==NULL){
            cout<<"\nTree Empty!!";
            return;
        }

        NODE *cur=root;
        while(cur){
            if(word == cur->word){
                cout<<"\nEnter new meaning::";
                cin>>cur->meaning;
                return;
            }
            else if(word > cur->word)
                cur=cur->RC;
            else
                cur=cur->LC;
        }
        cout<<"\nWord not found!";
    }
    
    
    void displayAscBST(NODE *t){
        if(t){
            displayAscBST(t->LC);
            cout<<"["<<t->word<<"|"<<t->meaning<<"]  ";
            displayAscBST(t->RC);
        }
    }
    
    void INORDBST(NODE *t){
        if(t){
            INORDBST(t->LC);
            S.push(t);
            INORDBST(t->RC);
        }
    }
    
    void displayDscBST(){
        INORDBST(root);
        while(!S.isEmpty()){
            NODE* t=S.pop();
            cout<<"["<<t->word<<"|"<<t->meaning<<"]  ";
        }
    }
    
    void searchNode(string key){
        int count=0;

        if(root==NULL){
            cout<<"\nTree Empty!!";
            return;
        }

        NODE *cur=root;
        while(cur){
            count++;
            if(key == cur->word){
                cout<<"\nWord found!";
                cout<<"\nNumber of comparisons: "<<count;
                return;
            }
            else if(key > cur->word)
                cur=cur->RC;
            else
                cur=cur->LC;
        }
        cout<<"\nWord not found!";
    }
    
    NODE* returnroot(){
        return root;
    }
    
    void deleteBST(NODE *t){
        if(t){
            deleteBST(t->LC);
            deleteBST(t->RC);
            delete t;
        }
        root=NULL;
    }
};

int main(){
    BST P;
    int choice=0;
    string word, meaning;

    while(choice != 7){
        cout<<"\n****************BST Operations**************";
        cout<<"\n1. Add Node";
        cout<<"\n2. Display BST";
        cout<<"\n3. Delete Node";
        cout<<"\n4. Update Node";
        cout<<"\n5. Search Node";
        cout<<"\n6. Delete BST";
        cout<<"\n7. Exit";
        cout<<"\nWhat operation you want::";
        cin>>choice;
        
        switch(choice){
            case 1:
                cout<<"\nEnter word::";
                cin>>word;
                cout<<"\nEnter meaning::";
                cin>>meaning;
                P.addNode(word,meaning);
                break;

            case 2:
                cout<<"\nAscending Order:\n";
                P.displayAscBST(P.returnroot());
                
                cout<<"\n\nDescending Order:\n";
                P.displayDscBST();
                break;

            case 3:
                cout<<"\nEnter word to be deleted::";
                cin>>word;
                P.deleteNode(word);
                break;

            case 4:
                cout<<"\nEnter word::";
                cin>>word;
                P.updateNode(word);
                break;

            case 5:
                cout<<"\nEnter word to be searched::";
                cin>>word;
                P.searchNode(word);
                break;

            case 6:
                P.deleteBST(P.returnroot());
                cout<<"\nBST Deleted Successfully!";
                break;

            case 7:
                cout<<"\nThanks for using application!!";
                break;

            default:
                cout<<"\nWrong Choice!!";
        }
    }
    return 0;
}