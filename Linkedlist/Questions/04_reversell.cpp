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

// efficient solution by reversing the links
Node *reverse(Node *head)
{
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL)
    {
        Node *next=curr->next;//to store the currents next
        curr->next=prev;//changing the link 
        prev=curr;//updating the previous pointer
        curr=next;//updating the current pointer
                    //no need to update next pointer as it wil automatically update as the loop starts
    }
    return prev;//the new head is previous
    
}

//recursive reverse 
Node *reverserecurrsive(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }//base case when linkedlist contains 1 or 0 elements
    Node *newhead=reverserecurrsive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    printlist(head);
    cout<<"after Reversing\n";
    head=reverserecurrsive(head);
    printlist(head);
  
}