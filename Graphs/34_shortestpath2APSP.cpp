#include<bits/stdc++.h>
using namespace std;
#define pb                  push_back   
#define ll                  long long int
const int MAXSIZE=505;
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    ll dist[MAXSIZE][MAXSIZE];

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
            dist[i][j]=1e12;

    }
    for(int i=0;i<m;i++)
    {
        ll x,y,wt;
        cin>>x>>y>>wt;

        dist[x][x]=0;
        dist[y][y]=0;
        dist[x][y]=min(dist[x][y],wt);
        dist[y][x]=min(dist[y][x],wt);
    }


    for(int k=1;k<n+1;k++)
    {
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(dist[a][b]<1e12)
            cout<<dist[a][b]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
