int postIndex;

TreeNode *construct(vector<int>& inorder, vector<int>& postorder,int instart,int inend,unordered_map<int,int>& mp)
{
    if(instart>inend )return NULL;
    
    TreeNode *root=new TreeNode(postorder[postIndex--]);
    
    int inIndex=mp[root->val];
    
    root->right=construct(inorder,postorder,inIndex+1,inend,mp);//Travel in postorder fashion
    root->left=construct(inorder,postorder,instart,inIndex-1,mp);
    
    
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;
    
    postIndex=postorder.size()-1;
    TreeNode *root=construct(inorder,postorder,0,inorder.size()-1,mp);
    return root;

}