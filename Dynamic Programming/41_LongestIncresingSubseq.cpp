

//O(n2) dp
/*
10    20        9       33          21        50 
1      2        1       3            2        4
10   (10,20)   (9)     (10,22,33)


*/
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size(),ans=0;
    int dp[n+1];//dp[i]-> Longest Increasing sub uptill i**
    dp[0]=1;
    
    for(int i=1;i<n;i++)
    {
        int mx=0;
        for(int j=0;j<i;j++)
        {
            if(nums[i]>nums[j])
                mx=max(mx,dp[j]);
        }
        dp[i]=1+mx;
    }
    
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}

//O(nlogn) Binary search: