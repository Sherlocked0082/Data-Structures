int ans;
int solve(TreeNode *root)
{
    if(root==NULL)return 0;
    
    int lval=solve(root->left);
    int rval=solve(root->right);
    ans=max(ans,root->val+max({0,lval,rval,lval+rval}));
    return root->val+max(0,max(lval,rval));
}
int maxPathSum(TreeNode* root) {
    ans=INT_MIN;
    int retval=solve(root);
    ans=max(ans,retval);
    return ans;
}
//Draw and visualize