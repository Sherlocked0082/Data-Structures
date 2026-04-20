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
//This solution uses two transvarsls
void middle(Node *head)
{
    if(head==NULL)
        return;
    Node *curr;
    int count=0;
    for(curr=head;curr!=NULL;curr=curr->next)
    {
        count++;
    }
    curr=head;
    for(int i=0;i<count/2;i++)
    {
        curr=curr->next;
    }
    cout<<curr->data;
    
}
//optimised solution using slow and fast pointers
//Slow pointer moves one node at a time and fat moves two node at a time
//so when fast reaches end slow reaches middle
//It finds middle of linkedilist in one tranversal
void printMiddleoptimised(Node * head){
    if(head==NULL)return;
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){//this condition is imp
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    // head->next->next->next->next=new Node(50);
    printlist(head);
    printMiddleoptimised(head);
    //middle(head);
  
}