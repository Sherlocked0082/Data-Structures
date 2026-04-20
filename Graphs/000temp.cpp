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

typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
const ll maxn = 1e5+6 ;
const ll MOD = 1e9 + 7  ;
const int MAXTprime=1e6;

void BFS(vector<int> adj[],int V,int s)
{
    bool visited[V+1];
    for(int i=1;i<=V;i++)
    {
        visited[i]=false;
    }
    visited[s]=true;
    queue<pair<int,string>> q;
    string strr=to_string(0);
    q.push({s,strr});
    string ans="0";
    while(q.empty()==false)
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
            int current=q.front().first;
            string currstr=q.front().second;
            q.pop();
            // cout<<current<<"->";
            // cout<<currstr<<" ";
            int j=0;
            for(int next:adj[current])
            {
                if(visited[next]==false)
                {
                    visited[next]=true;
                    string temp=to_string(j++);
                    q.push({next,currstr+temp});
                    ans+=currstr+temp;
                }
            }
        }

    }
    cout<<ans<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);        
    }
    BFS(adj,n+1,1);
    return 0;
}

