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

Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *prev=NULL;//temp variable
    Node *curr=head;
    while(curr->next!=NULL)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;

        curr=curr->next;
    }
    return prev->prev;
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