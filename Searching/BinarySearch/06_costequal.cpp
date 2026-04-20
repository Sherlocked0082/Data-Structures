//https://leetcode.com/problems/minimum-cost-to-make-array-equal/


//GOod qus on convex function
long long check(vector<int>& nums,vector<int> &cost,int num)
{
    long long ans=0;
    for(int i=0;i<nums.size();i++)
    {
        ans+=(long long)abs(nums[i]-num)*cost[i];
    }
    return ans;
}
long long minCost(vector<int>& nums, vector<int>& cost) {
    int mx=INT_MIN,mn=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        mx=max(mx,nums[i]);
        mn=min(mn,nums[i]);
    }
    long long lo=mn,hi=mx,mid,res=check(nums,cost,lo);
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        long long c1=check(nums,cost,mid);//2 checks as fx is a convex function
        long long c2=check(nums,cost,mid+1);
        res=min(c1,c2);
        if(c1<c2)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
}