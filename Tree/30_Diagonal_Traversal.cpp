vector<int> DiagonalTraversal(TreeNode* A) {
    vector<int> ans;
    if(A==NULL)return ans;
    queue<TreeNode*>q;
    q.push(A);

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode * currNode=q.front();
            q.pop();

            while(currNode!=NULL)
            {
                ans.push_back(currNode->val);
                if(currNode->left!=NULL)
                    q.push(currNode->left);
                currNode=currNode->right;
            }
        }
    }
    return ans;

}