//https://leetcode.com/problems/binary-tree-cameras/
//+1->child  has a camera and will cover its parent(currnode)
//-1->child  is in need of camera so currnode must have a camera(ans++)
//0->child  has got camera from its child
int cameras=0;
int monitor(TreeNode *root)
{
    if(root==NULL)return 0;
    
    int lv=monitor(root->left);
    int rv=monitor(root->right);
    
    if(lv==-1 || rv==-1)//child is in need of cam 
    {
        cameras++;
        return 1;
    }
    else if(lv==0 && rv==0)//has not got cam from any child 
        return -1;
    
    return 0;//has got cam from child nodes
}
int minCameraCover(TreeNode* root) {
    if(monitor(root)==-1)//if root itself is in need of camera and it has no parent to ask for
        cameras++;
    return cameras;
}

//----------------------------------------------------------------
//Similar quue distribute vaccines COVID:
// https://practice.geeksforgeeks.org/problems/d1afdbd3d49e4e7e6f9d738606cd592f63e6b0f0/1
int vaccines=0;
int distribute(Node *root)
{
    if(root==NULL)return 0;
    
    int lval=distribute(root->left);
    int rval=distribute(root->right);
    
    if(lval==-1 || rval==-1)
    {
        vaccines++;
        return 1;
    }
    else if(lval==0 && rval==0)
    {
        return -1;
    }
    return 0;//ok
}
int supplyVaccine(Node* root){
    // Your code goes here
    if(distribute(root)==-1)
        vaccines++;
    return vaccines;
}

//-------------------------------------------------------------------------------
