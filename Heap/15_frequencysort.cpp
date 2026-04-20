#include<bits/stdc++.h>

using namespace std;

//CHECK CUSTOM SORTING IN PQ  some kind of reverse

//here sorting based on frequency ie key is frequency 
//key can be frequency,difference,etc
void topkfrequent(int A[],int size)
{
    priority_queue<pair<int,int> >pq;//here we need most frequent element at top
    unordered_map<int,int> mp;
    for(int i=0;i<size;i++)
    {
        mp[A[i]]++;
    }
    for(auto x:mp)
    {
        pq.push({x.second,x.first});//imp 
        // if(pq.size()>k)
        // {
        //     pq.pop();
        // }
    }
    while(!pq.empty())
    {
        for(int i=0;i<pq.top().first;i++)
            cout<<pq.top().second<<" ";
        pq.pop();
    }
}
int main() 
{ 
    int arr[] = {1,1,1,1,3,2,2,2,4,4};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
    topkfrequent(arr,size);
    return 0;
} 

/*
Given an array of integers nums, sort the array in increasing order based on the frequency
 of the values. 
 If multiple values have the same frequency, sort them in decreasing order.
*/

class Solution {
public:
    class cmp{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b)
        {
            if(a.first==b.first)return a.second<b.second;
            
            return a.first>b.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        
        while(!pq.empty())
        {
            
            for(int i=0;i<pq.top().first;i++)
                ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};