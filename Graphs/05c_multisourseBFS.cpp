// 12. Distance of nearest cell having 1 
vector<vector<int>>nearest(vector<vector<int>>grid)
{	    
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>>ans(n,vector<int>(m,-1));

	queue<pair<int,int>> q ;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==1)//multiple sources
			{
				ans[i][j]=0;
				q.push({i,j});
			}
		}
	}
	
	int dx[] = {-1,  0, 1, 0};
	int dy[] = { 0, -1, 0, 1};
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		
		q.pop();
		
		for(int k=0;k<4;k++)
		{
			if(valid(x+dx[k],y+dy[k],n,m) && ans[x+dx[k]][y+dy[k]]==-1)
			{
				ans[x+dx[k]][y+dy[k]]=ans[x][y]+1;
				q.push({x+dx[k],y+dy[k]});
			}
		}
	}	
	return ans;
}