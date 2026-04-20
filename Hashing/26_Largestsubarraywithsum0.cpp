int maxLen(vector<int>&A, int n)
{   
    unordered_map<int,int> mp;
    mp[0]=-1;//imp
    int sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
        else
        {
            int len=i-mp[sum];
            ans=max(ans,len);
        }
    }
    return ans;
}