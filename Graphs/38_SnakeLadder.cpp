
int BFS(map<int,int> &mp,int n)
{
    unordered_set<int> visited;
    queue<int> q;
    q.push(1);
    visited.insert(1);
    int steps=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            int curr=q.front();
            q.pop();
            if(curr==n*n)
                return steps;
            for(int next=curr+1;next<=min(curr+6,n*n);next++)
            {
                int actualNext=next;
                if(mp.find(next)!=mp.end())
                    actualNext=mp[next];//Ladder or snake
                if(visited.find(actualNext)!=visited.end())
                    continue;
                visited.insert(actualNext);
                q.push(actualNext);
            }
        }
        steps++;
    }
    return -1;
}
int snakesAndLadders(vector<vector<int>>& board) {
    int n=board.size(),flag=1,idx=1;
    map<int,int> mp;//for snakes and ladders
    for(int i=n-1;i>=0;i--)
    {
        if(flag)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!=-1)
                    mp[idx]=board[i][j];
                idx++;
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                if(board[i][j]!=-1)
                    mp[idx]=board[i][j];
                idx++;
            }
        }
        flag=!flag;
    }
    return BFS(mp,n);
}