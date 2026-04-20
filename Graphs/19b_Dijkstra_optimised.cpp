#include<bits/stdc++.h>
using namespace std;
//Here there is no visited use it as it may give TLE
int main()
{
    int n,m,source;
    cin>>n>>m;
    vector<pair<int,int> > g[n];//0-indexed adjacency list for of graph

    int a,b,wt;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        g[a].push_back({b,wt});
        g[b].push_back({a,wt});
    }
    cout<<"\nEnter source\n";
    cin>>source;
    //---------------------------------------------------------------------------------------------------------------------
    //Algo->
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
    vector<int> distTo(n,INT_MAX);

    distTo[source]=0;
    pq.push({0,source});//{dist,from}

    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        for(auto it: g[prev])
        {
            int next=it.first;
            int nextdist=it.second;//weight
            if(distTo[next] > dist +nextdist)//relax
            {
                distTo[next] = dist +nextdist;
                pq.push({distTo[next],next});
            }
        }
    }
    cout << "The distances from source, " << source << ", are : \n";
	    for(int i = 0 ; i<n ; i++)	cout << distTo[i] << " ";
	    cout << "\n";
}
/*
ip
4 5
0 1 50
0 2 100
1 2 30 
1 3 200
2 3 20

0

4 4
0 1 3
0 2 5
2 3 -2
3 1 -3



int main(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll> > adj[n+1];

    for(int i=0;i<m;i++)
    {
        ll x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
    }
    
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>,greater<pair<ll,ll> > >pq;
    vector<ll > dist(n+1,LLONG_MAX);//LLONG_MAX as range
    vector<int> visited(n+1,0); //visited is imp for last 2 cases it gives TLE
    dist[1]=0;
    pq.push({dist[1],1});
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();

        if(visited[u])//
            continue;
        visited[u]=1;//

        for(auto p:adj[u])
        {
            ll v=p.first;
            ll wt=p.second;

            if(!visited[v] && dist[v] > dist[u] + wt)//
            {
                dist[v] =dist[u] + wt;
                pq.push({dist[v],v});   
            }
        }
    }

    for(int i=1;i<n+1;i++)
        cout<<dist[i]<<" ";

    return 0;
}
*/