#include<bits/stdc++.h> 
using namespace std; 
//unidrected graph
void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//FACT:
//If a Node is visited already there are 2 possibilities 
//1.It is parent of current Node//in this case there is not a cycle present in graph
//2.THere is another possible path which lead to this Node ie we reach to the same node via 2 different paths
//so  there is a cycle


//ALgo:
//Perform normal BFS maintain the parent (pair Node,parent)while traversing and if a node is already been visited then comapre it with parent to check whether there is cycle or not 
//Time+space->O(V+E)

bool BFS(vector<int> adj[],int s,bool visited[])
{
    queue<pair<int,int>> q;//{Node,parent}**
    visited[s]=true;
    q.push({s,-1});

    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto x:adj[node])
        {
            if(!visited[x])
            {
                visited[x]=true;
                q.push({x,node});//
            }
            else if(parent!=x)//
                return true;
        }
    }
    return false;
}

bool detectcycle(vector<int> adj[],int V)
{
    bool visited[V];
    
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(BFS(adj,i,visited))
                return true;
        }
    }
    return false;
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

    if(detectcycle(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

    return 0; 
} 
