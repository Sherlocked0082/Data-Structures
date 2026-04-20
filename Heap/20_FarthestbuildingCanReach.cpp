// https://leetcode.com/problems/furthest-building-you-can-reach/
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(int i=0;i+1<heights.size();i++)
    {
        if(heights[i]<heights[i+1])
        {
            pq.push(heights[i+1]-heights[i]);
            if(pq.size()>ladders)
            {
                int ht=pq.top();//take min as possible to make bricks
                pq.pop();
                if(ht>bricks)
                    return i;
                bricks-=ht;
            }
        }
    }
    return heights.size()-1;
}