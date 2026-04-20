// size of Array -> n+1
//Naive:Sort the Array and linearly traverse and if A[i]==A[i-1] 
//Time-> O(nlogn)
//Space->O(1) but modifying array

//Naive2: USing Hashing 
//Time->O(n)
//Space->O(n)


//Optimised :Linkedlist Cycle method
//Time->O(n)
//Space->O(1)
int findDuplicate(vector<int>& nums) {
    int slow=nums[0],fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);
    fast=nums[0];
    while(slow!=fast)
    {
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
    
}