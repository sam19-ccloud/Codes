#include<iostream>
#include<ios>  
#include<limits> 
#include <cstring>

#define MAX 20
using namespace std;

typedef struct Node{
    struct Node *LC;
    char data;
    struct Node *RC;
} NODE;

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


class ExpressionTree{
private:
    char exp[20];
    NODE* root;

public:
    ExpressionTree(){
        root=NULL;
    }

    void readPrefixExp(){
        cout<<"\nEnter Prefix expression::";
        cin>>exp;
    }

    void printPrefixExp(){
        cout<<"\nThe Prefix expression is::"<<exp;
    }

    bool isOperator(char token){
        return (token=='+' || token=='-' || token=='*' || token=='/' || token=='^');
    }


    bool isOperand(char token){
        return isalnum(token);
    }

    void generateExpTree(){
        Stack S;
        NODE *p;

        for (int i=strlen(exp)-1;i>=0;i--){
            p=new NODE;
            p->LC=NULL;
            p->data=exp[i];
            p->RC=NULL;

            if(isOperand(exp[i])){
                S.push(p);
            }
            else if (isOperator(exp[i])){
                NODE* left = S.pop();
                NODE* right = S.pop();

                if(left==NULL || right==NULL){
                    cout<<"\nInvalid Prefix Expression!";
                    return;
                }

                p->LC=left;
                p->RC=right;

                S.push(p);    
            }
        }

        root=S.pop();

        if(!S.isEmpty()){
            cout<<"\nInvalid Prefix Expression!";
        }
    }

    void displayET(NODE *t){
        if(t){
            if(isOperator(t->data)) cout<<"( ";
            displayET(t->LC);
            cout<<t->data<<" ";
            displayET(t->RC);
            if(isOperator(t->data)) cout<<") ";
        }
    }

    NODE* getRoot(){
        return root;
    }

    void nonRecursivePost(NODE* root){
        if (root == NULL)
            return;

        Stack stack1, stack2;
        stack1.push(root);
        NODE* node;

        while (!stack1.isEmpty()){
            node = stack1.pop();
            stack2.push(node);

            if (node->LC)
                stack1.push(node->LC);
            if (node->RC)
                stack1.push(node->RC);
        }

        while (!stack2.isEmpty()){
            node = stack2.pop();
            cout << node->data << " ";
        }    
    }

    void deleteTree(NODE* t){
        if(t){
            deleteTree(t->LC);
            deleteTree(t->RC);
            delete t;
        }
    }

    ~ExpressionTree(){
        deleteTree(root);
    }
};


int main(){
    ExpressionTree e1;
    int choice=0;

    while(choice!=6)
    {    
        cout<<"\n  Expression Tree  ";
        cout<<"\n1. Read Expression";
        cout<<"\n2. Print Expression";
        cout<<"\n3. Build Tree ";
        cout<<"\n4. Print Tree Inorder";
        cout<<"\n5. Print Tree Non Recurssive Postorder";
        cout<<"\n6. Exit Application";
        cout<<"\nEnter your choice::";
        cin>>choice;

        switch (choice){
            case 1:
                e1.readPrefixExp();
                break;
            case 2:
                e1.printPrefixExp();
                break;
            case 3:
                e1.generateExpTree();
                break;
            case 4:
                e1.displayET(e1.getRoot());
                break;
            case 5:
                e1.nonRecursivePost(e1.getRoot());
                break;
            case 6:
                cout<<"\nThanks for using Application!";
                break;
            default :
                cout<<"\nWrong choice!!";
        }
    }

    return 0;
}

