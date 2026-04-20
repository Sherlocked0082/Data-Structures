//famous aquire relase problem:
// https://leetcode.com/submissions/detail/719609528/


class Solution {
public:
int minSubArrayLen(int target, vector<int>& nums) {
    int n=nums.size(),l=0,r=0,ans=INT_MAX,sum=0;
    
    while(r<n)
    {
        if(sum+nums[r]==target)
        {
            ans=min(ans,r-l+1);
            sum+=nums[r];
            r++;
        }
        else if(sum+nums[r]>target)
        {
            ans=min(ans,r-l+1);
            sum-=nums[l];
            l++;

        }
        else
        {
            sum+=nums[r];
            r++;
        }
    }
    if(ans==INT_MAX)return 0;
    return ans;
    
}
};


//Variation 1:
//Minimum operations to set X to Zero
//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
int minOperations(vector<int>& nums, int x) {
        int sum=0,n=nums.size(),ans=-1;
        for(int i=0;i<n;i++)sum+=nums[i];
        if(sum<x)return -1;
        
        int target=0;
        int l=0,r=0;
        while(r<n)
        {
            if(target+nums[r]==(sum-x))
            {
                ans=max(ans,r-l+1);
                target+=nums[r];
                r++;
            }
            else if(target+nums[r]<(sum-x))
            {
                target+=nums[r];
                r++;
            }
            else
            {
                target-=nums[l];
                l++;
            }   
        }
        if(ans==-1)
            return -1;
        return n-ans;
    }