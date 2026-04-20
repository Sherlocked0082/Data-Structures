class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
    if(grid.size()==0)
        return 0;
    int n=grid.size(),m=grid[0].size();
    int cnt=0,days=0,target=0;
    
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
                q.push({i,j});
            else if(grid[i][j]==1)
                target++;//fresh
        }
    }
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=0;i<size;i++)//this is imp
        {
            int currx=q.front().first;
            int curry=q.front().second;
        
            q.pop();
        
            for(int i=0;i<4;i++)
            {
                int newx=currx+dx[i];
                int newy=curry+dy[i];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1)
                {

                    grid[newx][newy]=2;//now bcame rotten
                    cnt++;
                    q.push({newx,newy});
            
                }
            }
        
        }
        if(!q.empty())
            days++;
    }
    if(cnt==target)
        return days;
    return -1;
}
};