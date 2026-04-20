#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }

    int findUParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUParent(parent[node]);//whenever it returns a value store it (Path Compression)
    }

    void unionByRank(int u,int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);   
        if(ulp_u==ulp_v)return;
        //smaller one attaches to greater one
        if(rank[ulp_u]<rank[ulp_v]rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
}
int main(){
    
    return 0;
}

/*

*/
/*
DIsjoint Set

useful in dynamic graphs 
answers the quus DOes a and b belong the same structure
*/