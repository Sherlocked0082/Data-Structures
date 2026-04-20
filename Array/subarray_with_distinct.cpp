#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    unordered_map<int,int> freq,mp;
    // cout<<mp[0]<<endl;
    int n=A.size(),ans=0;
    int pref[n];
    for(int i=0;i<n;i++)
    {
        freq[A[i]]++;
        pref[i]=freq.size();
    }
    mp[0]++;

    for(int i=0;i<n;i++)
    {
        int target=pref[i]-B;
        if(mp.find(target)!=mp.end())
        {
            ans+=mp[target];
            cout<<target<<" mp->";
            cout<<mp[target]<<endl;
        }
        mp[target]++;
    }
    return ans;

}

int main()
{
    vector<int> ans;
    ans.push_back(5);
    ans.push_back(3);
    ans.push_back(5);
    ans.push_back(1);
    ans.push_back(3);
    int B=3;
    cout<<solve(ans,B);
}
