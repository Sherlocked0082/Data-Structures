//Level order traversal of a tree is breadth first traversal of binary tree.
//recursion is not a good choice here
#include<bits/stdc++.h>
using namespace std;
//Time complexity->theta(n)
//auxiliary space->o(w)
//Interesting fact-->In Queue there is atmst 1 level at a time
//so to be precise auxiliary space of queue is width of tree.
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

//USe the concept of Vertical Line
//Top view will be 1st elements of every vertical lines :)
vector<int> topview(Node *root)
{
    vector<int> ans;
    if(root==NULL)return ans;

    map<int,int> mp;//level->Node
    queue<pair<Node*,int>>q;//Node,level
    q.push({root,0});

    while(!q.empty())
    {
        Node *currNode=q.front().first;
        int level=q.front().second;
        q.pop();

        if(mp.find(level)==mp.end())//Not to overwrite so ..
        {
            mp[level]=currNode->key;
        }

        if(currNode->left!=NULL)
            q.push({currNode->left,level-1});
        
        if(currNode->right!=NULL)
            q.push({currNode->right,level+1});
    }

    for(auto x:mp)
    {
        ans.push_back(x.second);
    }
    return ans;
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
    vector<int> ans=topview(root);
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
                        
