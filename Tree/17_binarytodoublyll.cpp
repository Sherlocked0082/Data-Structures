#include<bits/stdc++.h>
using namespace std;
// ####
// Inorder conversion of Binary Tree to Doubly Linked List.
// A function that takes root of a Binary Tree and converts it into a Doubly linked list.
// Hint:- we need to do the inorder traversal of the Tree and while doing inorder traversal
//  we can simply maintain a previous pointer or reference of the previously traversed node.
//   And change right child of the previous node to current node and left child of current node as previous.

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
    }
};
//first Node in inorder travreal must be the head of dll
// so when prev of any node is NUL it is the head of binary tree(SImilar to make a Lnkedlist without a dummy Node)
//time->o(n)
// space->o(h)
Node *BTtoDLL(Node *root)
{
    if(root==NULL)
        return root; 
    static Node *prev=NULL;//imp()
    Node *head=BTtoDLL(root->left);
    if(prev==NULL)//this will only execute once
    {
        head=root;
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTtoDLL(root->right);
    return head;
}

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);

    }
}
void printList(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->key<<"<=>";
        curr=curr->right;
    }cout<<endl;
}
int main()
{
    Node *root=new Node(10);
	root->left=new Node(5);
	root->left->left=new Node(67);
	root->left->right=new Node(57);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
    inorder(root);
    Node *head=BTtoDLL(root);
    cout<<endl;
	printList(head);
    return 0;
}

//---------------------------------------------------------------------
Node *prev=NULL,*head=NULL;//for start;
void convert(Node *root)
{
    if(root==NULL)return ;

    bToDLL(root->left);
    
    if(prev==NULL)
    {
        head=root;
        // prev=root;
    }
    else
    {
        prev->right=root;
        root->left=prev;
    }
    prev=root;

    bToDLL(root->right);
}
//Function to convert binary tree to doubly linked list and return it.
Node * bToDLL(Node *root)
{
    convert(root);    
    return head;
}             
