#include<bits/stdc++.h>
using namespace std;

//Amortized Time Complexity -> O(alpha*n)
//------------------------------------------------------------
const int N=1e5+10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find(int v)
{
    if(v==parent[v])return v;
    //Path Compression
    return parent[v]=find(parent[v]);
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
    {   //Union by size
        if(size[a] < size[b])
            swap(a,b);//a will always be bigger tree
        parent[b]=a;
        size[a]+=size[b];
    }
}
//--------------------------------------------------------------
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==i)
            connected_cnt++;
    }
    cout<<"Number of connected components : "<<connected_cnt<<endl;
    return 0;
}

/*

*/
/*
DIsjoint Set

useful in dynamic graphs 
answers the quus DOes a and b belong the same structure
*/
//----------------------------------------------------------------------------------
class Solution {
public:
    int parent[100000];
    int size[100000];

    void make(int v)
    {
        parent[v]=v;
        size[v]=1;
    }

    int find(int v)
    {
        if(v==parent[v])return v;
        //Path Compression
        return parent[v]=find(parent[v]);
    }

    void Union(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {   //Union by size
            if(size[a] < size[b])
                swap(a,b);//a will always be bigger tree
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int> adj[n];
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[vals[i]].push_back(i);
        }

        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            if(vals[u]>=vals[v])
                adj[u].push_back(v);
            else if(vals[v]>=vals[u])
                adj[v].push_back(u);
        }
        //DSU
        for(int i=0;i<n;i++)
            make(i);

        for(auto x:mp)
        {
            for(auto it:adj[x.second])
            {
                Union(it,x.second);
            }
        }

        
    }
};