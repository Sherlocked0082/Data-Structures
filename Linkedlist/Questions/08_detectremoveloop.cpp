//MUST CHECK THIS ALGOS MATHEMATICAL ANALYSIS
#include <bits/stdc++.h> 
using namespace std;
/*
1.detect loop using floyd algorithm
2.move the loop to the beginning of linkedlistand keep fsat at meeting point
**After 2nd step check whether slow and fast are already at same node 
3.Now one by one move slow and fast (at same speed)
IMP->>>>>THE POINT WHERE THEY WILL MEET NOW IS THE FIRST NODE OF LOOP(STARTING POINT OF LOOP)
*/
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
//detection of loop using floyd algorithm
bool detectloop(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

//detection using FLOYD ALGO and removal
void detectremove(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast!=NULL && fast->next!=NULL)//Condition a
    {
        prev=fast;//TO CHECK WHETEHR THE LL IS CIRCULAR  (CORNER CASE)*****
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)//Condition b
        {
            break;
        }
    }
    if(slow!=fast)//this is to ensure that the loop is not there that is the upper while loop is broken by condition a and not by condition b
    {
        return;
    }
    slow=head;//starting slow form head
    if(slow==fast)//VIMP CASE OF CIRCULAR LINKEDLIST*****
    {
        prev->next->next=NULL;
        return;
    }
    while(fast->next!=slow->next)//THIS IS IMPORTANT (To remove the loop we need to change last 
    //node of it,to change the next of last node we need to get hold of it so we just checkthe next of slow and next of fast
    //)
    {
        slow=slow->next;//moving both slow and fast at same speed
        fast=fast->next;
    }
    fast->next=NULL;//
}

int main()
{
    Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;
    cout<<"Before removing the loop\n";
    if(detectloop(head))
        cout<<"Loop is there\n";
    else    
        cout<<"Loop is not there\n";

    detectremove(head);
    cout<<"After removing the loop\n";
    if(detectloop(head))
        cout<<"Loop is there\n";
    else    
        cout<<"Loop is not there\n";
    printlist(head);

  
}