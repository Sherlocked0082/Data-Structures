//https://leetcode.com/problems/distribute-coins-in-binary-tree/

int moves=0;
int distribute(TreeNode *root)
{
    if(root==NULL)return 0;
    int lval=distribute(root->left);
    int rval=distribute(root->right);
    
    moves+=abs(lval) + abs(rval);
    
    return root->val+lval+rval-1;
}
int distributeCoins(TreeNode* root) {
    distribute(root);
    return moves;
}