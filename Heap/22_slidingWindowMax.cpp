//has to be done with deque but can be done by pq

//Method 1: Priority Queue
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;i++)
        pq.push({nums[i],i});
    ans.push_back(pq.top().first);
    for(int i=k;i<nums.size();i++)
    {
        pq.push({nums[i],i});//firstly we have to push 
        while(pq.top().second<i-k+1)//invalid in window
            pq.pop();
        ans.push_back(pq.top().first);
    }
    return ans;
}

