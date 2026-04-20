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
int countelements(Node *head)
{
    Node *curr=head;
    int count=1;
    while(curr->next!=NULL)
    {
        count++;
        curr=curr->next;
    }
    return count;
}
int getintersection(int d,Node *head1,Node *head2)
{
    Node *curr1=head1;
    Node *curr2=head2;
    for(int i=0;i<d;i++)
    {
        if(curr1==NULL)//
            return -1;
        curr1=curr1->next;
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        //________________MIMP________________
        if(curr2==curr1)//imp here not to check the data instead check pointers 
        {
            return curr1->data;
        }
        curr2=curr2->next;
        curr1=curr1->next;
    }   
    return -1;
}
int get_intersection(Node *head1,Node *head2)
{
    int c1=countelements(head1);
    int c2=countelements(head2);
    int d;
    if(c1>c2)
    {
        d=c1-c2;
        return getintersection(d,head1,head2);
    }
    else
    {
        d=c2-c1;
        return getintersection(d,head2,head1);
    }
}
int main()
{
    /* 
		Creation of two linked lists 
	
		1st 3->6->9->15->30 
		2nd 10->15->30 
	
		15 is the intersection point 
	*/

	Node* newNode; 

	Node* head1 = new Node(10); 

	Node* head2 = new Node(3); 

	newNode = new Node(6); 
	head2->next = newNode; 

	newNode = new Node(9); 
	head2->next->next = newNode; 

	newNode = new Node(15); 
	head1->next = newNode; 
	head2->next->next->next = newNode; 

	newNode = new Node(30); 
	head1->next->next = newNode; 

	head1->next->next->next = NULL; 
    cout<<"list 1:\n";
    printlist(head1);
    cout<<"list 2:\n";
    printlist(head2);
    cout<<"Intersection:\n";
	cout <<get_intersection(head1, head2); 
} 
  

//--------------------------------------------------------------
int count(Node *head)
{
    int cnt=1;
    Node *curr=head;
    while(curr!=NULL)
    {
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int c1=count(head1);
    int c2=count(head2);
    Node *curr1=head1,*curr2=head2;
    if(c1>c2)
    {
        for(int i=0;i<(c1-c2);i++)
        {
            curr1=curr1->next;
        }
        
    }
    else
    {
         for(int i=0;i<(c2-c1);i++)
        {
            curr2=curr2->next;
        }
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1==curr2)
            return curr1->data;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    
    return -1;
}