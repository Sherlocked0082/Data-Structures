#include<bits/stdc++.h>
using namespace std;

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
USing Inorder Traversal
*/
bool Path(Node *root,vector<int> &ans,int x)
{
    if(root==NULL)
        return false;
    
    ans.push_back(root->key);

    if(root->key==x)
        return true;
    
    if(Path(root->left,ans,x) || Path(root->right,ans,x))
        return true;
    
    ans.pop_back();//VIMP
    return false;
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
    // printLevel(root);
    vector<int> ans;
    Path(root,ans,50);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}
/*
              10
        20          30
      40  50          70
                         80  
                         */
                        
