#include<bits/stdc++.h>
using namespace std;
//LOWEST (LEVEL) COMMON ANCESTORS    topmost height is highest  
//ancestor of a NOE is NOde itself its parent its its parent and so on
//LCA can also be used to find the distance b/w 2 nodes
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
Naive:
Populate the PAths of both Nodes and then check all common elements
but it requires 2 traversals and more space

*/
bool PopulatePath(TreeNode *root,TreeNode *target,vector<TreeNode*> &temp)
{
    if(root==NULL)return false;
    temp.push_back(root);
    
    if(target->val==root->val)
        return true;
    if(PopulatePath(root->left,target,temp) || PopulatePath(root->right,target,temp))
        return true;
    
    temp.pop_back();
    return false;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode *> p1,p2;
        PopulatePath(root,p,p1);
        PopulatePath(root,q,p2);
        int i=0,j=0;
    TreeNode *ans=NULL;
    while(i<p1.size() && j<p2.size())
    {
        if(p1[i]->val==p2[j]->val)
            ans=p1[i];
        else
            break;
        i++,j++;
    }
    return ans;
}


/*
optimsed
*/
Node *LCA(Node *root,Node *p,Node *q)
{
    if(root==NULL || root==p || root==q)
        return root;

    Node *left=LCA(root->left,p,q);
    Node *right=LCA(root->right,p,q);

    if(left==NULL)
        return right;
    else if(right==NULL)
        return left;
    else//both are Not NULL
        return root
}

/*
Optimised
*/

int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=20,n2=50;
	
	Node *ans=lca(root,n1,n2);
	cout<<"LCA: "<<ans->key;
    return 0;
}

                        
