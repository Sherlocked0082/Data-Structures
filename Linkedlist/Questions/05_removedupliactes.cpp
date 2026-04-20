#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void printlist(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    cout<<endl;
}

//head is never modified by this function
void removeduplicates(Node *head)
{
    Node *curr=head;
    while(curr!=NULL && curr->next!=NULL)//we need to ensure that current is also not null as null->next will give segmentation fault
    {
        if(curr->data==curr->next->data)
        {
            Node *temp=curr->next;//a(a and b are to ensure that there i no memory leak)
            curr->next=curr->next->next;//Main logic
            delete(temp);//b(a and b are to ensure that there i no memory leak)
        }
        else
            curr=curr->next;
    }
}
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(3);
    head->next->next->next->next->next=new Node(3);

    printlist(head);
    cout<<"after removing duplicates\n";
    removeduplicates(head);
    printlist(head);
  
}