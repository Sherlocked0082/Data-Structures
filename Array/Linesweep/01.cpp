https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/
int minGroups(vector<vector<int>>& intervals) {
    int ans=0,sum=0;
    map<int,int> mp;
    for(auto it:intervals)
    {
        mp[it[0]]++;
        mp[it[1]+1]--;
    }
    for(auto x:mp)
    {
        sum+=x.second;
        ans=max(ans,sum);
    }
    return ans;
}

//HARD Line sweep + binary search 
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/?envType=daily-question&envId=2023-10-11
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        map<int,int> mp;
        for(auto it:flowers)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sum=0;
        for(auto x:mp)
        {
            sum+=x.second;
            mp[x.first]=sum;
        }
        for(auto x:people)
        {
            if(mp.find(x)!=mp.end())
                ans.push_back(mp[x]);
            else
            {
                auto it=mp.lower_bound(x);
                if(it==mp.begin())
                {
                    ans.push_back(0);
                }
                else
                {
                    it--;
                    ans.push_back((*it).second);
                }
                
            }
            
        }
        return ans;

    }
};