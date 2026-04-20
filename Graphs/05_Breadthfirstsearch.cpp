//Given an undirected graph and a source vertex 's' ,print B.F.S. from given source.
#include<bits/stdc++.h>
using namespace std;
//BFS-> print the source then its chldren and then its childrens childrens and so on...
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//Time ->O(V + E) vimp analysis can check vdo
void printGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void BFS(vector<int> adj[],int V,int s)
{
    bool visited[V+1];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    visited[s]=true;//here visited does not mean this vertex has been printed here visitdemeans this vertex has been added to queue
    queue<int> q;
    q.push(s);
    while(q.empty()==false)
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        for(int next:adj[current])
        {
            if(visited[next]==false)
            {
                visited[next]=true;//Here visited means this vertex has been added to queue
                q.push(next);
            }
        }
    }
}
int main()
{
    int V=5;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3);
	addEdge(adj,3,4);
	addEdge(adj,2,4);
    // addEdge(adj,1,2);
    // addEdge(adj,1,5);
    // addEdge(adj,1,3);
    // addEdge(adj,2,6);
    // addEdge(adj,2,4);
    // addEdge(adj,5,4);
    // addEdge(adj,3,4);
    // addEdge(adj,3,7);

    cout<<"print graph\n";
    printGraph(adj,V);
    cout<<"The BFS of graph is\n";
    BFS(adj,V,0);
    return 0;
}
