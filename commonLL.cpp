#include <iostream>
using namespace std;

class linklist
{
private:
    struct node {
        int data;
        node *next;
    }*head;

public:
    linklist()
    {
        head=NULL;
    }

    void append(int num)
    {
        node *temp,*tempoo;
        if(head==NULL) {
            temp=new node;
            temp->data=num;
            temp->next=NULL;
            head=temp;
        }

        else {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;

            tempoo=new node;
            tempoo->data=num;
            tempoo->next=NULL;
            temp->next=tempoo;
        }
    }


    void common(linklist a, linklist b)
    {
        for (node *x = a.head; x != NULL; x = x->next)
            for(node *y = b.head; y != NULL; y = y->next)
                if (x->data == y->data) {
                    node *z = head;
                    while (z != NULL) {
                        if (z->data == y->data)
                            break;

                        z = z->next;
                    }
                    if (z == NULL)
                        append(x->data);
                }
    }

    void all_ele(linklist a,linklist b)
    {
        for( node *x=a.head ; x!=NULL ; x=x->next ) {      //for first linklist
            node *z = head;
            while (z != NULL) {
                if (z->data == x->data)
                    break;

                z = z->next;
            }
            if (z == NULL)
                append(x->data);
        }
        for( node *y=b.head ; y!=NULL ; y=y->next ) {     // for second ll
            node *z = head;
            while (z != NULL) {
                if (z->data == y->data)
                    break;

                z = z->next;
            }
            if (z == NULL)
                append(y->data);
        }
    }

    void display()
    {
        node *t=head;
        while(t!=NULL) {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }
};



int main()
{
    linklist A,B,C,D;
    A.append(3);
    A.append(7);
    A.append(10);
    A.append(10);
    A.append(16);
    A.append(9);
    A.append(22);
    A.append(17);
    A.append(32);
    cout<<"Displaying contents of L.L A:\n";
    A.display();
    B.append(16);
    B.append(2);
    B.append(9);
    B.append(13);
    B.append(37);
    B.append(10);
    B.append(10);
    B.append(1);
    B.append(28);
    cout<<"Displaying contents of L.L B:\n";
    B.display();
    C.common(A,B);
    cout<<"Displaying common elements of both L.L:\n";
    C.display();
    D.all_ele(A,B);
    cout<<"Displaying all elements of A and B:\n";
    D.display();
    return 0;
}
