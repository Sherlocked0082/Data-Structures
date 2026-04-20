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
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
void rprint(Node *Head)
{
    if(Head==NULL)
        return;
    cout<<(Head->data)<<" ";
    rprint(Head->next);
}

//Inserting a element at the beginning
Node *insertBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    temp->next=head;
    return temp;
}

Node *insertEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

Node *deleteHead(Node *head)
{
    if(head==NULL)
        return NULL;
    else{
        Node *temp=head->next;
        delete head;
        return temp;
    }

}
Node *deletelastnode(Node *head)
{
    //These two cases are handeled because we need to ensure that there are minimum two nodes in linked list
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=NULL;
    return head;
}
int main()
{
    //printing the elements
    // Node *head=new Node(10);
    // head->next=new Node(20);
    // head->next->next=new Node(30);
    // head->next->next->next=new Node(40);
    // printlist(head);
    // cout<<endl;
    // rprint(head);
    //Inserting a element at the head;
    Node *head=NULL;
    head=insertBegin(head,30);
    printlist(head);
    head=insertBegin(head,20);
    printlist(head);
    head=insertBegin(head,10);
    printlist(head);
    head=insertEnd(head,1);
    printlist(head);
    head=insertEnd(head,2);
    printlist(head);
    head=insertEnd(head,3);
    printlist(head);
    head=deleteHead(head);
    printlist(head);
    head=deletelastnode(head);
    printlist(head);

}