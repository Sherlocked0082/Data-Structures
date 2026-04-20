#include<bits/stdc++.h>
using namespace std;

/*Naive
consider eery activity as first activity 
recursively find out maximum aci=tivities startng fro mthese activities
time-> exponential
can be optimised by DP but a better solun will be greedy
*/

/*
Optimised:
1.Sort acc to increasing order of finishing tie//nlogn
2.Initialize our solution as first activity(Always pick the activity which finishes first)
3.DO the following://n-1 times
    a.if curr activity overrides with last picked acti ignore the curr activity
    b.Else add to curr activity 



TIME->O(nlogn+n)~O(logn)




*/
void cmp(pair<int,int>a,pair<int,int> b)
{
    return (a.second<b.second);
}

int ActivitySelection(vector<pair<int,int>>time)
{
    int n=time.size();
    int prev=0;
    int res=1;
    for(int curr=1;curr<n;curr++)
    {
        if(time[curr].first>=time[prev].first)
        {
            res++;
            prev=curr;
        }
    }
    return res;
}

int main()
{
    vector<pair<int,int>> time=[{1,4},{2,3},{5,8},{6,10}];
    cout<<ActivitySelection(time)<<endl;
    return 0;
}



static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        
        int ans=1,pre=0;
        for(int i=1;i<n;i++)
        {
            if(v[i].first>v[pre].second)
            {
                ans++;
                pre=i;
            }
        }
        
        return ans;
    }

//Max meeting attended
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second==b.second)return a.first<b.first;
        
        return a.second<b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
            vp.push_back({start[i],end[i]});
        sort(vp.begin(),vp.end(),cmp);
        
        int ans=1,pre=0;//taken the first meeting in ans 
        for(int i=1;i<n;i++)
        {
            if(vp[i].first>vp[pre].second)//here it shouldnt be same
            {
                ans++;
                pre=i;
            }
        }
        return ans;
    }