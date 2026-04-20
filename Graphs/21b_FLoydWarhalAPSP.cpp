//see this C 53

// Floyd Warshall Algorithm 
// (All Pair Shortest Path Algorithm)
// Based on DP

// dist[i][j] = shortest distance from node i to node j 
// initially all dist[i][j]= INFINITY if there is no edge of i to j 
// dist[i][j] = weight(i,j) if there is edge from it to j 
// dist[i][i]=0;


for(int k=0; k<n; k++)
{
    for(int i=0; i<n; i++)
	{	
	        for(int j=0; j<n; j++)
                {
                        dp[i][j]  = min(dp[i][j], dp[i][k] + dp[k][j]);//we are trying all posibilities and findin gshortest path from i->j via intermidiate node k
                }
	}
}

// Time complexity: O (V3)
void shortest_distance(vector<vector<int>>&dp){
    // Code here
    int n=dp.size();
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==k || j==k || i==j || dp[k][j]==-1 || dp[i][k]==-1 ){
                    continue;
                }
                if(dp[i][j]==-1){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
                else
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
        }
    }
}

/*
Q.WHy we dont use different matrices in A-1 A2 A3....
The Values which are involved in updation in kth iteration are Dist[i][k] and Dist[k][j]
ie the only values which are usefull in kth loop are in kth row and kth column are used to calculate all dist[i][j]

During calculation the kth row and kth column values do not change
So we can use same matrix fr Ak ij to save space
check in SAHANI book
*/
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
