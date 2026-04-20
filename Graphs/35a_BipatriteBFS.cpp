
#include<bits/stdc++.h> 
using namespace std; 
//unidrected graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//observation:
//If a graph doesnt have a odd length cycle it is Bypatrite
//without even length also the graph can be bipatrite


//ALgo:

//Time+space->O(V+E)

bool BFS(vector<int> adj[],int s,vector<int> &color)
{
    queue<int> q;
    color[s]=1;//initially color it with 1
    q.push(s);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto x:adj[node])
        {
            if(color[x]==-1)//if this node is not coloured
            {
                color[x]=1-color[node];
                q.push(x);
            }
            else if(color[x]==color[node])//if node is coloured
                return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[],int V)
{
    vector<int> color(V,-1);
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(!BFS(adj,i,color))
                return false;
        }
    }
    return true;
}

int main() 
{ 
    int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

    if(checkBipartite(adj,V))
	    cout<<"Bipartite";
	else
	    cout<<"Not a Bipartite";

    return 0; 
} 


