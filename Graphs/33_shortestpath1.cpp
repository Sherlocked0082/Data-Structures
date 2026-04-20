#include<bits/stdc++.h>
using namespace std;
#define pb                  push_back   
#define ll                  long long int

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
