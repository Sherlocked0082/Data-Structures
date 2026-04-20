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
/*
after the first pass the node which is last node(prev) it is the head
after nth pass the node which is last node(prev) is the head of this sublist

1.head of nth pass -> prev
2.prevfirst(curr) will be lastnode of previous pass
so for linking 
    prevFirst->next=prev
*/
// efficient solution by reversing the links
Node *reverse_insizeofk(Node *head, int k)
{
    Node *curr=head,*prevFirst=NULL;
    bool isFirstpass=true;//for setting head in firstpass
    while(curr!=NULL)
    {
        Node *first=curr,*prev=NULL;
        int count=0;
        while(curr!=NULL && count<k)//running multiple passes
        {
            Node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(isFirstpass)//only in firstpass
        {
            head=prev;//last node is prev
            isFirstpass=false;//make false so that subsequent passes never come here 
        }
        else//to connect individual reverse linedlist
        {
            prevFirst->next=prev;//prev->head of current pass   .
        }
        prevFirst=first;//store previous first as it is last Node 
    }
    return head;
}

//recursive reverse in size of k
Node *reverserecurrsive(Node *head, int k)
{
    Node *prev=NULL,*curr=head,*next;
    int count=0;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        Node *resthead=reverserecurrsive(next,k);
        head->next=resthead;
    }
    return prev;
}
int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=new Node(60);

    printlist(head);
    int k=3;
    cout<<"after Reversing recursively in grps of "<<k<<"\n";
    head=reverserecurrsive(head,k);
    printlist(head);
    cout<<"after Reversing iteratively in grps of "<<k<<"\n";
    head=reverse_insizeofk(head,k);
    printlist(head);
}