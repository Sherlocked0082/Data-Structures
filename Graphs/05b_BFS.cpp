// B.F.S on disconnected graphs.
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
void BFS(vector<int> adj[],int s,bool visited[])
{
    queue<int> q;
    visited[s] = true; 
    q.push(s);
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int next:adj[curr])
        {
            if(visited[next]==false)
            {
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

void BFS_Disconnected(vector<int> adj[],int V)
{
    // int count=0;
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false){
            BFS(adj,i,visited);
            // count++;
        }
    }
    // cout<<"c-"<<count;
}
int main()
{

    int V=7;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,2,3); 
	addEdge(adj,1,3); 
	addEdge(adj,4,5);
	addEdge(adj,5,6);
	addEdge(adj,4,6);

	cout << "Following is Breadth First Traversal: "<< endl; 
	BFS_Disconnected(adj,V); 
    return 0;
}

//check 01 BFS it is done with help of dequeue
