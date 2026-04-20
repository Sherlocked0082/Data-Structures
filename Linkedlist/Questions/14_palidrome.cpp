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
Node *reverselist(Node *head)
{
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL)
    {
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool ispalidrome(Node *head)
{
    if(head==NULL)
        return true;
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)//This is to get first imddle in case of even nodes
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //now the middle is in slow
    Node *rev=reverselist(slow->next);
    
    Node *curr=head;
    while(rev!=NULL){
        if(rev->data!=curr->data)
            return false;
        rev=rev->next;
        curr=curr->next;
    }
    return true;
}
int main()
{
    Node *head=new Node('N');
	head->next=new Node('A');
	head->next->next=new Node('a');
	if(ispalidrome(head))
	    cout<<"Yes";
	else
	    cout<<"No";
	return 0;
    
} 
  
