#include<iostream>
using namespace std;

struct node
{
    int data;
    node *LC;
    node *RC;
};

class AVL
{
    node *root;

public:
    AVL()
    {
        root=NULL;
    }

    node* getroot()
    {
        return root;
    }

    int height(node *T)
    {
        if(T==NULL)
            return -1;

        int lh = height(T->LC);
        int rh = height(T->RC);

        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }

    int difference(node *T)
    {
        return height(T->LC) - height(T->RC);
    }

    node* ll_rotate(node *P)
    {
        cout<<"LL Rotation\n";

        node *A = P->LC;
        P->LC = A->RC;
        A->RC = P;

        return A;
    }

    node* rr_rotate(node *P)
    {
        cout<<"RR Rotation\n";

        node *A = P->RC;
        P->RC = A->LC;
        A->LC = P;

        return A;
    }

    node* lr_rotate(node *P)
    {
        cout<<"LR Rotation\n";

        P->LC = rr_rotate(P->LC);
        return ll_rotate(P);
    }

    node* rl_rotate(node *P)
    {
        cout<<"RL Rotation\n";

        P->RC = ll_rotate(P->RC);
        return rr_rotate(P);
    }

    node* balance(node *T)
    {
        int bf = difference(T);

        if(bf > 1)
        {
            if(difference(T->LC) > 0)
                T = ll_rotate(T);
            else
                T = lr_rotate(T);
        }

        else if(bf < -1)
        {
            if(difference(T->RC) > 0)
                T = rl_rotate(T);
            else
                T = rr_rotate(T);
        }

        return T;
    }

    node* insert(node *T,int val)
    {
        if(T==NULL)
        {
            T = new node;
            T->data = val;
            T->LC = NULL;
            T->RC = NULL;

            root=T;
            return T;
        }

        if(val < T->data)
            T->LC = insert(T->LC,val);

        else if(val > T->data)
            T->RC = insert(T->RC,val);

        T = balance(T);

        root=T;
        return T;
    }

    void display(node *T)
    {
        if(T!=NULL)
        {
            display(T->LC);

            cout<<"Node: "<<T->data;
            cout<<"  Balance Factor: "<<difference(T)<<endl;

            display(T->RC);
        }
    }
};

int main()
{
    AVL tree;
    int choice,val;

    do
    {
        cout<<"\n---- AVL TREE ----";
        cout<<"\n1. Insert Number";
        cout<<"\n2. Display Tree (with Balance Factor)";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter number: ";
                cin>>val;
                tree.insert(tree.getroot(),val);
                break;

            case 2:
                cout<<"\nAVL Tree (Inorder)\n";
                tree.display(tree.getroot());
                break;
        }

    }while(choice!=3);

    return 0;
}