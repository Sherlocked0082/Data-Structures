#include<iostream>
using namespace std;
/*
IMP ASSUMPTION Equal elements are also allowed for peak element
Idea->
    In independent Array there is a peak element 

Here we apply bs 
Now how to decide which part to skip?
    if A[mid-1]>=A[mid]  then there is a peak elemt in left half for sure
    else   peak element in right half
*/

int peak_element(int A[],int n,int x)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;

        if((mid==0 || A[mid-1]<=A[mid]) && (mid==n-1 || A[mid+1]<=A[mid]))
        {
            return mid;
        }
        if(mid>0 && A[mid-1]>=A[mid])
            hi=mid-1;
        else
            lo=mid+1;
    }
    return -1;
}

int main()
{
    int A[6]={10,20,40,60,5,8};
    int n=6,x=5;
    cout<<peak_element(A,n,x);

    return 0;
}
/*
int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1 || nums[0]>nums[1])
        return 0;
    if (nums.back() > nums[n-2]) return n-1;
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
        if(nums[mid]<nums[mid+1])
            lo=mid+1;
        else
            hi=mid-1;    
    }
    return -1;
}
*/