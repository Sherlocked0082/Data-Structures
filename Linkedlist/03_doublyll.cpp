#include <bits/stdc++.h> 
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data=d;
        prev=NULL;
        next=NULL;
    }
};
//insert at the beginning
Node *insertBegin(Node *head,int data)
{
    Node *temp=new Node(data);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}
//insert data at the end 
Node *insertend(Node *head,int data)
{
    Node *temp=new Node(data);
    Node *curr=head;
    if(head==NULL)
        return temp;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;//
    return head;
}

//delete head of dl
Node *delhead(Node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}
//delete the tail of dl
Node *deleteTail(Node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

        Node *curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->prev->next=NULL;//imp
        delete curr;
        return head;
    
}
int main()
{
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    
}