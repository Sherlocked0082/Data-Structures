//GOod Quues 
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/solutions/2821874/why-sliding-window-works-for-this-qustion-and-how-it-works-simple-analysis/
//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
int longestSubstring(string s, int k) {
    unordered_set<char> st(s.begin(),s.end());
    int mxunique=st.size(),ans=0;
    for(int unique=1;unique<=mxunique;unique++)
    {
        unordered_map<char,int> mp;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;//Acquire
            while(j<s.size() && mp.size()>unique)//IF current window contains characters which has more unique characters then shrink it
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    mp.erase(s[j]);
                j++;
            }

            int flag=1;
            for(auto x:mp)//Only check the ans if current window has every characters occ>=k
            {
                if(x.second<k)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                ans=max(ans,i-j+1);

        }
    }
    return ans;
}