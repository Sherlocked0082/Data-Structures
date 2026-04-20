#include<iostream>
using namespace std;
//NAive generate All the subarrays and find max -> O(n2)
int maxSubarraySum


//maximum subarray sum
int Kadane_Algo(int A[],int n)
{
    int sum=0;
    int maxium=INT_MIN;
    //carry subarray as long it gives positive sum
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        maximum=max(maximum,sum);
        if(sum<0)
            sum=0;

    }
    return maximum;
}

//Cumulative sum approach  O(n2)
int maxSubarraySum(int A[],int n)
{
    int prefix[n+1];
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        prefix[i]=prefix[i-1]+A[i-1];
    }

    int maxSum=INT_MIN;
    for(int i=1;<=n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)
        {
            sum+=prefix[i]-prefix[j];
            maxSum=max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
}

//brute force -> O(n3)

int main()
{
    
}

//----------------------------------------------------
// Varitaion 1: Circular Kadane_Algo:
//https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/880413739/
int maxSubarraySumCircular(vector<int>& nums) {
    int n=nums.size();
    int sum=0,ans=INT_MIN,total=0,curr=0,mnsum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        total+=nums[i];//total sum
        sum+=nums[i];//for max sum
        curr+=nums[i];//for min sum
        ans=max(ans,sum);
        mnsum=min(mnsum,curr);
        if(curr>0)//min sum
            curr=0;
        if(sum<0)//max sum
            sum=0;
        
    }
    return mnsum==curr?ans:max(ans,total-mnsum);//atleast 1 subbaray element
}
//--------------------------------------------------------------------------------------
//Variation 3:kadane with one deleted
int maximumSum(vector<int>& arr) {
    int n=arr.size();
    if(n==1)
        return arr[0];
    vector<int> psum,ssum(n);
    int sum=0,mx=INT_MIN,ans=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,arr[i]);
        sum+=arr[i];
        if(sum<0)
            sum=0;
        psum.push_back(sum);
    }
    sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=arr[i];
        if(sum<0)
            sum=0;
        ssum[i]=sum;
    }
    ans=ssum[0];
    for(int i=1;i<psum.size()-1;i++)
    {
        ans=max(ans,psum[i-1]+ssum[i+1]);
    }
    ans=max(ans,psum[n-2]);
    if(ans==0)
        return mx;
    return ans;
}