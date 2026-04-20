TreeNode *prev=NULL;
void flatten(TreeNode* root) {
    if(root==NULL)return;
    flatten(root->right);
    flatten(root->left);

    root->right=prev;
    root->left=NULL;
    prev=root;
}

/*
Do some sort of Reverse Postorder
tC->O(n)
space->recursive O(n)
*/
 void flatten(TreeNode* root) {
    //iterative
    if(root==NULL)return ;
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode *currNode=st.top();
        st.pop();
        if(currNode->right!=NULL)
            st.push(currNode->right);
        if(currNode->left!=NULL)
            st.push(currNode->left);
        if(!st.empty())
            currNode->right=st.top();
        currNode->left=NULL;
    }
}