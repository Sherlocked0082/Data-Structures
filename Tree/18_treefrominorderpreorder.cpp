//here we need to construct the tree when inorder and preorder are given
//IMP->we can construct tree only when out of 2 traversals one traversal is Inorder
//so we can construct only when   1.Inorder+preorder  2.Inorder+postorder
#include<bits/stdc++.h>
using namespace std;
                        
/*
!st elemt in preorder is root
COntruct the Node in preorder fashion
#include <bits/stdc++.h>
using namespace std;
*/
struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  
/*
we are constructing tree in preoder traversal
Just maintaining preindex variable we pick next item from preorder traversal 
make it root and then search it in inorder traversal and find left side  of it 
and right side of it recursively construct left subtree and right subtree
and then connect these subtree with the root and return root

TIme->O(n2) fir every node we do O(n) work

Can be optimised
HAshing 
store inorder traversal keys 
Instead of linearly searching we can look in hash table and they can be pass as parameter to function
whith hashing 
O(n)

*/

//TIME->80ms  memory 25mb
int preIndex=0;
Node *construct_Tree(int inorder[],int preorder[],int instart,int inend)
{
    if(instart>inend)return NULL;

    Node *root=new Node(preorder[preIndex++]);

    int inIndex;
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==root->key)
        {
            inIndex=i;
            break;
        }
    }

    root->left=construct_Tree(inorder,preorder,instart,inIndex-1);
    root->right=construct_Tree(inorder,preorder,inIndex+1,inend);
    return root;
}
//-----------------------------------------------------------------------
//Optimised TIme12ms:)  26.4mb
int preIndex=0;
TreeNode *construct(vector<int>& preorder, vector<int>& inorder,int instart,int inend,unordered_map<int,int>& mp)
{
    if(instart>inend)return NULL;
    
    TreeNode *root=new TreeNode(preorder[preIndex++]);
    
    int inIndex=mp[root->val];

    root->left=construct(preorder,inorder,instart,inIndex-1,mp);
    root->right=construct(preorder,inorder,inIndex+1,inend,mp);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    TreeNode *root=construct(preorder,inorder,0,inorder.size()-1,mp);
    return root;
}
//-----------------------------------------------------------------------
int main() {
	
	int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};
	int n=sizeof(in)/sizeof(in[0]);
	Node *root=construct_Tree(in, pre, 0, n-1);
	inorder(root);
}