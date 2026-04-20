#include<bits/stdc++.h>
using namespace std;

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
/*
Boundary Order TRaversal=
Left Boundary excluding leaf+
Leaf Nodes+
RIght Boundary in reverse
*/
bool isLeaf(Node *root)
{
    return (root->right==NULL && root->left==NULL);
}
void addLeftBoundary(Node *root,vector<int> &ans)
{
    Node *curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))ans.push_back(curr->key);

        if(curr->left!=NULL)
            curr=curr->left;
        else
            curr=curr->right;
    }
}

void addRightBoundary(Node *root,vector<int> &ans)
{
    stack<int> st;
    Node *curr=root->right;
    while(curr)
    {
        if(!isLeaf(curr))st.push(curr->key);

        if(curr->right!=NULL)
            curr=curr->right;
        else
            curr=curr->left;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

void addLeaves(Node *root,vector<int> &ans)//simply do do inorder traversal and add leaves
{
    if(isLeaf(root)){
        ans.push_back(root->key);
        return ;
    }
    if(root->left!=NULL)
        addLeaves(root->left,ans);
    if(root->right!=NULL)
        addLeaves(root->right,ans);
}
vector<int> BoundaryOrderTrversal(Node *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    if(!isLeaf(root))ans.push_back(root->key);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}

int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->right->right->right=new Node(80);
    
    vector<int> ans=BoundaryOrderTrversal(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
/*
              10
        20          30
      40  50          70
                         80  
                         */
                        
