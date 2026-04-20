
//all 4 directions allowed
//4 directions--> Graph DIjstra
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool checkvalid(int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=m || j>=n)return false;
    return true;
}
int minimumCostPath(vector<vector<int>>& grid) 
{
    int m=grid.size(),n=grid[0].size();
    // pair<int,pair<int,int>> //->weight{x,y}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,0}});
    
    int dist[m][n];
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    dist[i][j]=INT_MAX;
    
    dist[0][0]=grid[0][0];
    while(!pq.empty())
    {
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        if(checkvalid(x,y,n,m))
        {
            for(int i=0;i<4;i++)
            {
                int newX=x+dx[i];
                int newY=y+dy[i];
                
                if(checkvalid(newX,newY,n,m))
                {
                    if(dist[newX][newY]>dist[x][y]+grid[newX][newY])
                    {
                        dist[newX][newY]=dist[x][y]+grid[newX][newY];
                        pq.push({dist[newX][newY],{newX,newY}});
                        
                    }
                }
            }
        }
    }
    // Code here
    return dist[m-1][n-1];
}