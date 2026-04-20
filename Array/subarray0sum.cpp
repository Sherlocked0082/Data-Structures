//VIMP
#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0
            || sumSet.find(sum)
            != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
 
// Driver code
int main()
{
    int arr[] = { 1,2,-2,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
/*
arr[] = {1, 4, -2, -2, 5, -4, 3}
        ----s1->
        -----------s2->
    (s2-s1)=0
case1:s2=s1      case2:s2=s1=0    
So If we consider all prefix sums, we can
notice that there is a subarray with 0
sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.

Prefix sums for above array are:
1, 5, 3, 1, 6, 2, 5

Since prefix sum 1 repeats, we have a subarray
with 0 sum.
*/


//Variation :https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/0/?track=DSASP-Hashing&batchId=154#
//COunt subarry with equal zero and ones(Count no of subarrays with zero sum)
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    //convert into subarray with zero sum
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            arr[i]=-1;
    }
    unordered_map<int,int> mp;
    long long ans=0,sum=0;
    mp[0]=1;//IMP
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(mp.find(sum)!=mp.end())
            ans+=mp[sum];//count number of times the previous sum repeats
        mp[sum]++;
    }
    return ans;
}

//Another method using Combinations:
ll findSubarray(vector<ll> A, int n ) {
    unordered_map<ll,int> mp;
    mp[0]=1;
    ll sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        mp[sum]++;
    }
    for(auto x:mp)
    {
        if(x.second>1)
        {
            int n=x.second;
            ans+=((n)*(n-1))/2;
        }
    }
    return ans;
    //0 0 5 10 10 10
}