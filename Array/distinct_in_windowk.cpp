#include<bits/stdc++.h>
using namespace std;

vector<int> disitnct(vector<int> &A, int k) {
    int n=A.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++)
        mp[A[i]]++;
    ans.push_back(mp.size());
    for(int i=1;i<n-k+1;i++)
    {
        
        mp[A[i-1]]--;
        mp[A[i+k-1]]++;
        if(mp[A[i-1]]==0)//for some compillers if frequency of a element is 0 then it is also taken in consideration for size
            mp.erase(A[i-1]);
        ans.push_back(mp.size());
    }
    return ans;
}

int main()
{
    vector<int>A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    A.push_back(3);

    vector<int> ans=disitnct(A,3);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}