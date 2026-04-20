#include<iostream>
using namespace std;
/*
SUppose there is a SOrted+rotated array then 
One half of the input will always be sorted
How to check which half is sorted?
    we can compare the first elelemt with mid and the last elemet wiht mid 
*/
int search(int nums[], int target,int n) {
    // int n=nums.size();
    int lo=0,hi=n-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid] >= nums[lo])//left sorted
        {
            if(nums[mid]>target && nums[lo]<=target)//lies in range
            {
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        else//right sorted
        {
            if(nums[mid]<target && target<=nums[hi])//lies in range
            {
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
    }
    return nums[lo] == target ? lo : -1;;//IMP if lo<=hi
}

int main()
{
    int A[19]={101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100 };
    int n=19,x=202;
    cout<<search(A,x,n);

    return 0;
}

//variation : Search in Biotonic Array
// https://www.interviewbit.com/problems/search-in-bitonic-array/
/*
A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
int Solution::solve(vector<int> &A, int B) {
    int n=A.size(),lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(A[mid]==B)
            return mid;
        if(A[mid]>=A[lo])//left increasing
        {
            if(A[lo]<=B && B<A[mid])
            {
                hi=mid-1;    
            }
            else
            {
                lo=mid+1;
            }
        }
        else//right decreasing
        {
            if(A[lo]>=B && B>A[mid])
            {
                hi=mid-1;
            }
            else
                lo=mid+1;
                
        }
    }
    return -1;

}


















*/