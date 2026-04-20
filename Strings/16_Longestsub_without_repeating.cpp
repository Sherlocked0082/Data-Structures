 int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int r=0,l=0,ans=0;
        while(r<s.size())
        {
            if(mp[s[r]]==0)//aquire till valid
            {
                int ln=r-l+1;
                ans=max(ans,ln);
                mp[s[r]]++;
                r++;    
            }
            else//release till invalid
            {
                mp[s[l]]--;
                l++;
            }
            
        }
        return ans;
    }

//---------------------------------------------------
int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int ans=INT_MAX,en=0,start=0,found=0,n=cards.size();
        while(en<n)
        {
            if(mp[cards[en]]<1)//aquire till not found
            {
                mp[cards[en]]++;
                en++;
            }
            else//release till valid to get minimum
            {
                found=1;
                int ln=en-start+1;
                ans=min(ans,ln);
                mp[cards[start]]--;
                start++;
            }
        }
        if(found)
            return ans;
        return -1;
    }
    // https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/