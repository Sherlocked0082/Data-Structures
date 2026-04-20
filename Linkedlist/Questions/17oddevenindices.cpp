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
//all odd indices nodes->evenindices node
Node *rearrange_oddeven_indices(Node *head)
{
    if(head==NULL)
        return NULL;
    Node *odd=head;
    Node *even=head->next;
    Node *evenhead=even;

    while(even!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}
//all even indices->all odd indices
Node *rearrange_evenodd_indices(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node *odd=head;
    Node *even=head->next;
    Node *oddhead=odd;
    Node *evenhead=even;

    while(even->next!=NULL)//here only this bcas we need to do even->next=oddhead and if even is NULL we cant do this
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        if(even->next!=NULL)
            even=even->next;
    }
    odd->next=NULL;//imp
    even->next=oddhead;
    return evenhead;
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    cout<<"Before rearranging\n";
    printlist(head);
    head=rearrange_oddeven_indices(head);
    cout<<"After rearranging odd indices Nodes->even indices Nodes\n";
    printlist(head);
    head=rearrange_evenodd_indices(head);
    cout<<"After rearranging even indices Nodes->odd indices Nodes\n";
    printlist(head);
    
}