#include <bits/stdc++.h> 
using namespace std;
/*there are many methods like modify the structur ,modify pointers,using hash table.
(FLOYDS ALGORITHM)
here we create fast and slow pointers 
concept->if there is a loop then fast and slow pointers will always meet
Proof->
1.Fast pointer will always enter the loop before slow pointer or with slow pointer
2.Let fast pointer be k distance ahead of slow pointer
when slow pointer enters the loop when k>=0
3.This distance keeps on increasing by one in every movement of both pointer
4.When distance becomes length of cycle they meet
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
//detection using FLOYD ALGO
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
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(12);
    head->next->next->next=new Node(20);
    head->next->next->next->next=head->next;
    if(detectloop(head))
        cout<<"Loop is there";
    else    
        cout<<"Loop is not there";
  
}