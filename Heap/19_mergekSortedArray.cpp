vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        int n=arr.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int> idx(n,0);//this shows the current index of the array
        vector<int> ans;
        
        for(int i=0;i<k;i++)
            pq.push({arr[i][0],i});//push 1st elements of each array 
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            int i=pq.top().second;
            pq.pop();
            
            idx[i]++;
            if(idx[i]<k)
                pq.push({arr[i][idx[i]],i});
        }
        
        return ans;
        
        
    }