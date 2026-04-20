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

vector<int> teamNumber;
bool DFS(vector<int> adj[],int node,int currTeam,vector<int> &visited)
{
    visited[node]=1;
    teamNumber[node]=currTeam;

    for(auto child:adj[node])
    {
        if(teamNumber[child]==teamNumber[node])//
            return false;
        if(!visited[child])
        {
            visited[child]=1;
            bool temp=DFS(adj,child,3-currTeam,visited);//
            if(!temp)//
                return false;
        }
    }
    return true;
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
        adj[b].push_back(a);
        
    }
    teamNumber.resize(n+1);//
    vector<int> visited(n+1,0);
    bool temp;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            temp=DFS(adj,i,1,visited);
            if(!temp)
            {   
                 cout<<"IMPOSSIBLE\n";
                break;
            }   


        }
    }
    // cout<<temp<<endl;
    if(temp)
    {
        for(int i=1;i<teamNumber.size();i++)
            cout<<teamNumber[i]<<" ";
    }

    return 0;
}

