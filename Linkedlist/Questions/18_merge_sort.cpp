#include <bits/stdc++.h> 
using namespace std;
//VIMP
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

Node *Divide(Node *head)
{
    Node *slow=head,*fast=head->next,*nptr;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    nptr=slow->next;
    slow->next=NULL;
    return nptr;
}
Node *Merge(Node *lptr, Node *nptr)
{   
    Node *result,*ptr1,*ptr2,*tail;
    ptr1=lptr;
    ptr2=nptr;

    if(ptr1->data < ptr2->data)
    {
        result=ptr1;
        ptr1=ptr1->next;
    }
    else
    {
        result=ptr2;
        ptr2=ptr2->next;
    }
    tail=result;
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data < ptr2->data)
        {
            tail->next=ptr1;
            tail=tail->next;
            ptr1=ptr1->next;
        }
        else
        {
            tail->next=ptr2;
            tail=tail->next;
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=NULL)
        tail->next=ptr1;
    else
        tail->next=ptr2;
    
    return result;
}
/*
MergeSort
    1. Divide array/Linked-list in two equal halves.
    2. Sort each part individually by using Mergesort 
    3. Merge two sorted parts.
*/
Node *MergeSort(Node *head)
{
    Node *nptr;
    if(head!=NULL && head->next!=NULL)
    {
        nptr=Divide(head);
        head=MergeSort(head);
        nptr=MergeSort(nptr);
        head=Merge(head,nptr);
    }
    return head;
}

int main()
{
    Node *head=new Node(6);
    head->next=new Node(2);
    head->next->next=new Node(1);
    head->next->next->next=new Node(8);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(1);

    cout<<"List before sorting\n";
    printlist(head);
    head=MergeSort(head);
    cout<<"List after sorting\n";
    printlist(head);
}