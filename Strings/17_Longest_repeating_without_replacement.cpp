// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 int characterReplacement(string s, int k) {
        int l=0,maxfrq=0,ans=0;
        unordered_map<int,int> mp;
        for(int r=0;r<s.size();r++)
        {
            mp[s[r]]++;
            maxfrq=max(maxfrq,mp[s[r]]);
            
            while(((r-l+1) - maxfrq) > k)//release for invalid
            {
                mp[s[l]]--;
                l++;
            }
            
            ans=max(ans,r-l+1);
        }
        return ans;
    }