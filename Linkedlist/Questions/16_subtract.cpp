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

int countNOde(Node *head)
{
    int c=0;
    Node *t=head;
    while(t!=NULL)
    {
        c++;
        t=t->next;
    }
    return c;
}

Node * subtract(Node *A)
{
    int count = countNOde(A);
    if(count%2!=0)
        count++;

    count/=2;
    Node *temp=A;
    stack<int> s;
    int i=0;
    while(temp!=NULL)
    {   
        if(i>=count)
        {
            s.push(temp->data);
        }
        i++;
        temp=temp->next;
    }
    temp=A;
    i=0;
    while(i<count)
    {
        if(!s.empty())
        {
            int x=temp->data;
            temp->data=(s.top()) - (x);
            s.pop();
        }
        else
            break;
        temp=temp->next;
        i++;
    }
    return A;
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(3);
    head->next->next->next->next=new Node(3);
    head->next->next->next->next->next=new Node(3);

    printlist(head);
    head=subtract(head);
    // cout<<countNOde(head)<<endl;
    printlist(head);
  
}