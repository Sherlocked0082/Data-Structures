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

Node *insertpos(Node *head,int pos,int data)
{
    Node *temp=new Node(data);
    //corner case
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=0;i<pos-2;i++)
    {
        curr=curr->next;
    }
    //This is to check whether user gives a position which is beyong linkedlist size+1; 
    if(curr==NULL)
    {
        return head;
    }

    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int searchl(Node *head,int key)
{
    int pos=1;
    Node *curr=head;
    while(curr!=NULL)
    {
        if(curr->data==key)
        {
            return pos;
        }
        else{
            curr=curr->next;
            pos++;
        }
    }
    return -1;
}
int rsearch(Node *head,int key)
{
    int pos=1;
    if(head==NULL)
    {
        return -1;
    }
    if(head->data==key)
    {
        return 1; 
    }
}
int main()
{
    
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
    head=insertpos(head,3,103);
    printlist(head);
    cout<<searchl(head,3);
    

}