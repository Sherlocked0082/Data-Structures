 TreeNode *prev=NULL;
    bool ans;
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            if(prev!=NULL)
            {
                if(root->val<=prev->val)
                    ans=false;    
            }
            prev=root;
            inorder(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        ans=true;
        inorder(root);
        return ans;
    }