    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        
        vector<int> smp(26,0),pmp(26,0);
        vector<int> ans;
        for(int i=0;i<p.size();i++)
            pmp[p[i]-'a']++;
        for(int i=0;i<p.size();i++)
        {
            smp[s[i]-'a']++;
        }
        if(smp==pmp)
            ans.push_back(0);
        if(p.size()==s.size())
        {
            if(smp==pmp)
                return ans;
            else
                return {};
        }
        for(int i=1;i<s.size()-p.size()+1;i++)
        {
            smp[s[i-1]-'a']--;
            smp[s[i+p.size()-1]-'a']++;
            // if(smp[s[i-1]]==0)
            //     smp.erase(s[i-1]-'0');
            if(smp==pmp)
                ans.push_back(i);
        }
        return ans;
    }
//Manual hashmaps are good if u wanna compare 
//this soln took 14ms    8.7mb
// and hashmap solun took 1526 ms 248mb
