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

//Naive solution
//Here we need to do two transversals
void printnthnode(Node *head,int n)
{
    Node *curr=head;
    int count=0;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        count++;
    }
    if(n>count)
    {
        return;
    }
    curr=head;
    for(int i=0;i<(count-n+1);i++)
    {
        curr=curr->next;
    }
    cout<<curr->data<<endl;
}
//-------------------------------------------------------
//check this
//optimised solution using two pointers
//very good method
void printnthnodeoptimised(Node *head,int n)
{
    if(head==NULL)
        return;
    Node *first=head;
    for(int i=0;i<n;i++)
    {
        if(first==NULL)//THis condition means that linkedlist has less no of nodes than n;(IMP CONDI)
            return;
        first=first->next;
    }
    Node *second=head;
    while(first!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    cout<<second->data<<endl;
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    printlist(head);
    printnthnode(head,1);
    printnthnodeoptimised(head,2);
  
}