class Solution {
public:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int,int> > adj[n+1];
    for(int i=0;i<times.size();i++)
    {
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    
    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int> > >pq;
    vector<int> dist(n+1,INT_MAX);
    
    dist[k]=0;
    pq.push({dist[k],k});
    int maxtime=-1;
    while(!pq.empty())
    {
        int d=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        
        for(auto it:adj[prev])
        {
            int next=it.first;
            int wt=it.second;
            if(dist[next]> d+wt)
            {
                dist[next]=d+wt;
                pq.push({dist[next],next});
            }
        }
        
    }
    for(int i=1;i<n+1;i++)//the min time woll be max of all the shortest paths but it must be computed at the end
        maxtime=max(maxtime,dist[i]);
    if(maxtime==INT_MAX)
        return -1;
    return maxtime;
}
};