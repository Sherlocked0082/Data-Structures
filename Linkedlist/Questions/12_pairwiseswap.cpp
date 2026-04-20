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
//solution by changing links
// Node *pairwiseswap(Node *head)
// {

// }

Node *pairwiseswap_recursive(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;
    
    Node *first=head;
    Node *second=first->next;
    
    Node *temp_list=pairwiseswap_recursive(second->next);
    first->next=temp_list;//b4 joining it with first it must be rearranged so called the recursive func above
    second->next=first;

    return second;//after changing links second becomes newhead
}
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    cout<<"Before swapping\n";
    printlist(head);
    head=pairwiseswap_recursive(head);
    cout<<"After swapping\n";
    printlist(head);
  
}