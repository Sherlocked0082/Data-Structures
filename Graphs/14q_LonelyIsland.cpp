//Probability+Toposort  type quus of Hackerearth
// https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)          for(int i=a;i<b;i++)
#define Fo(i,k,n)           for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll                  long long int
#define pb                  push_back
#define mp                  make_pair
#define deb(x)              cout << #x << "=" << x << endl
#define all(x)              x.begin(), x.end()
#define clr(x)              memset(x, 0, sizeof(x))
#define sortall(x)          sort(all(x))
#define PI                  3.1415926535897932384626

#define maxn 200005
#define maxlgn 20


void solve(int t) {
    // cout<<"Case #"<<t<<": ";
    ll n,m,source;
    cin>>n>>m>>source;
    vector<ll> indeg(n+1,0),outdeg(n+1,0);
    vector<double> ways(n+1,0);
    vector<ll> adj[n+1];
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }
    queue<ll> q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
    ways[source]=1.0;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(auto next:adj[node])
        {
            ways[next]+=(ways[node]*1.0)/outdeg[node];//probability
            indeg[next]--;
            if(indeg[next]==0)
                q.push(next);
        }
    }
    double mx=0.0;
    // for(int i=1;i<=n;i++)
    //     cout<<ways[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(outdeg[i]==0 && ways[i]>mx)
            mx=ways[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(outdeg[i]==0 && abs(ways[i]-mx)<=1e-9)
            cout<<i<<" ";
    }
    cout<<endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    rep(i,1,t+1) solve(i);
    return 0;
}
