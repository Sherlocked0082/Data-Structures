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
Node *segregateevenodd(Node *head)
{
    Node *eS=NULL,*eE=NULL,*oS=NULL,*oE=NULL;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
    {
        int x=curr->data;
        if(x%2==0)
        {
            if(eS==NULL)
            {
                eS=curr;
                eE=eS;
            }
            else{
                eE->next=curr;
                eE=eE->next;
            }
        }
        else
        {
            if(oS==NULL)
            {
                oS=curr;
                oE=oS;
            }
            else
            {
                oE->next=curr;
                oE=oE->next;
            }
        }
    }
    if(oS==NULL || eE==NULL)
        return head;
    eE->next=oS;
    oE->next=NULL;
    return eS;
}
int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    cout<<"Before segregating\n";
    printlist(head);
    head=segregateevenodd(head);
    cout<<"After segregating\n";
    printlist(head);
  
}