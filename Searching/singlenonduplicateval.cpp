class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),lo=0,hi=n-1;
        
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid]==nums[mid-1]))
                lo=mid+1;
            else
                hi=mid;
                
        }
        return nums[lo];
    }
};
/*
//1 1 2 3  3  4 4 8 8
 lo        m        hi
 l    m    h
 l  m h
 
 1 2 2 3 3
  l   m    h
  l h 
 
 1 1 2 3 3
 l   m   h
 */