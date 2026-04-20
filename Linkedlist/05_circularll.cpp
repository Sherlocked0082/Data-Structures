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
void printl(Node *head)
{
    if(head==NULL)
        return;
    cout<<head->data<<"->";
    for(Node *p=head->next;p!=head;p=p->next)
    {
        cout<<p->data<<"->";
    }
    cout<<endl;
}
//using do while it is prefferd to use do while as we have to execute the statement once
void printdw(Node *head)
{
    if(head==NULL)
        return;
    Node *p=head;
    do
    {
        cout<<p->data<<"->";
        p=p->next;
    } while (p!=head);
    
}
//Naive solution to insert at the neginning
//o(n) solution
Node *insertbegin(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
        temp->next=temp;
    Node *curr=head->next;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    return temp;
}

//optimised solution for inserting is to insert after the head and swap the data it with head
Node *insertbeginOptimised(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;

        //swapping the data of head and temp;
        int temp_data=head->data;
        head->data=temp->data;
        temp->data=temp_data;
        return head;
    }
}
//Naive solution to insert at end o(n)
Node *insertend(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        Node *curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        return head;
    }
}
//Efficient solution to insert at tail
Node *insertendoptimised(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;

        //swapping the data of head and temp;
        int temp_data=head->data;
        head->data=temp->data;
        temp->data=temp_data;
        return temp;//imp->temp is now new head
    }
}

//DEleting the head node of the linkedlist(Naive solution)
Node *deletehead(Node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=head->next;
    delete(head);
    head=curr->next;
    return head;
}
//Deleting the head in a optimised way 
//copy the data of node next to head and delete the node next to head
Node *deleteheadoptimised(Node *head)
{
    if(head==NULL)
        return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}
//delete the kTh node
Node *deletekthnode(Node *head,int k)
{
    if(head==NULL)
        return NULL;
    if(k==1)
    {
        return deletehead(head);
    }
        Node *curr=head;
        for(int i=0;i<k-2;i++)
        {
            curr=curr->next;
        }
        Node *temp=curr->next;
        curr->next=curr->next->next;
        delete(temp);
        return head;
}

int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=head;
    printl(head);

    head=insertbegin(head,103);
    printdw(head);
    cout<<endl;
    head=insertbeginOptimised(head,301);
    printdw(head);

    cout<<"\ninserting at tail\n";
    head=insertend(head,120);
    printdw(head);
    cout<<endl;
    head=insertendoptimised(head,1222);
    printdw(head);
    cout<<"\ndeleting the head\n";
    head=deletehead(head);
    printdw(head);
    cout<<"\n deleting the kth node\n";
    head=deletekthnode(head,4);
    printdw(head);
}