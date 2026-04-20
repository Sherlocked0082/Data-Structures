class Solution {
public:
int findMin(vector<int>& nums) {
    int n=nums.size(),lo=0,hi=n-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        
        if(nums[mid]>nums[hi])
            lo=mid+1;
        else
            hi=mid;
    }
    return nums[lo];
}
    /*
    
     3  4  5  1  2
     l     m      h
              lm  h
               lh
    
    4  5  6  7  0  1  2
    l        m         h
                l  m   h
    
    */
    
    
    
};

//Duplicates
int findMin(vector<int>& nums) {
    int n=nums.size(),lo=0,hi=n-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        
        if(nums[mid]>nums[hi])
            lo=mid+1;
        else if(nums[mid]<nums[hi])
            hi=mid;
        else//nums[mid]==nums[hi]
            hi--;
    }
    return nums[lo];
}