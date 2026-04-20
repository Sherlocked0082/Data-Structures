int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;//assumed sum 0 at index-1
        int sum=0,rem,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if(rem<0)
                rem+=k;
            mp[rem]++;
        }
        for(auto x: mp)
        {
            if(x.second>1)
            {
                int n=x.second;
                ans+=((n)*(n-1))/2;
            }
        }
        return ans;
    }
/*
//1   2   3    4    5    6    7    8
------->s1%k=m
-------------------------->s2%k=m
then s2-s1 will be divisible by k *****VIMP


*/
//Method 2 :Running counting
//Instead of counting pairs after wards count it while running
class Solution {
public:
    //Method 2:Running count
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[0]=1;
        for(auto x:nums)
        {
            sum+=x;
            int rem=sum%k;
            if(rem<0)
                rem+=k;
            ans+=mp[rem];//Every newly added element forms a pair with previous 
            mp[rem]++;
        }
        return ans;
    }
};

//------------------------------VARIATION 2
int longSubarrWthSumDivByK(int A[], int n, int k)
	{
	    unordered_map<int,int> mp;
	    mp[0]=-1;
	    int sum=0,rem,ans=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=A[i];
	        int rem=sum%k;
	        if(rem<0)
	            rem+=k;
	       if(mp.find(rem)!=mp.end())
	            ans=max(ans,i-mp[rem]);
	       else
	            mp[rem]=i;
	    }
	    return ans;
	}