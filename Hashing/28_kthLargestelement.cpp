vector<int> kthLargest(int k, int arr[], int n) {
    vector<int>ans;
    priority_queue<int,vector<int>,greater<int>>pq;//n-kth smallest
    // code here
    for(int i=0;i<k-1;i++){
        pq.push(arr[i]);
        ans.push_back(-1);
    }
    for(int i=k-1;i<n;i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
            pq.pop();
        ans.push_back(pq.top());
    }
    return ans;
}