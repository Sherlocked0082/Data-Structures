#include<bits/stdc++.h> 
using namespace std; 
/*
ALGO;
1.Relax all vertices for V-1 times
2.Atlast we will get shortest distance

time->O((v-1)*E)


ADvantage
1.Can be used for negative weights
2********
IMP->
this algo can detect if there are negative cycles*
after V-1 relaxation if we get that in Vth relaxation the distance changes ie there is a negative 
cycle
*/
struct node{
    int u,v,wt;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }    

};

int main()
{
    //Direcred graph input
    int n,m;
    cin>>n>>m;
    vector<node> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    int source;
    cout<<"Enter source\n";
    //-----------------------------------------------------
    cin>>source;
    vector<int> distance(n,INT_MAX);
    distance[source]=0;

    for(int count=0;count<n-1;count++)
    {
        for(auto it: edges)
        {
            if(distance[it.v] > distance[it.u] + it.wt)
            {
                distance[it.v] = distance[it.u] + it.wt;
            }
        }
    }
    //-------------------------------------------------------
    //Negative cycle detection
    int found=0;
    for(auto it:edges)
    {
        if(distance[it.v] > distance[it.u] + it.wt)
        {
            cout<<"NEGATIVE CYCLE\n";
            found=1;
        }
    }
    //----------------------------------------------------------------
    //PRinting distance if negative cycles not found
    if(!found)
    {
        cout<<"Displaying Vertex distance from source\n";
        for(int i=0;i<n;i++)
        {
            cout<<i<<"  "<<distance[i]<<endl;
        }
    }
    return 0;
}
/*
ip

4 5
0 1 1
0 2 4
1 2 -3
1 3 2
2 3 3

0


*/

/*
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:

    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V,100000000);
        dist[S]=0;
        for(int i=1;i<=V-1;i++)
        {
            for(int i=0;i<adj.size();i++)
            {
                int u=adj[i][0];
                int v=adj[i][1];
                int wt=adj[i][2];
                
                if(dist[v]>dist[u]+wt)
                    dist[v]=dist[u]+wt;
                
            }
        }
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends





*/