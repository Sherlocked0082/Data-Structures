int minimumCardPickup(vector<int>& cards) {
    unordered_map<int,int> mp;
    int ans=INT_MAX,en=0,start=0,found=0,n=cards.size();
    while(en<n)
    {
        if(mp[cards[en]]<1)
        {
            mp[cards[en]]++;
            en++;
        }
        else
        {
            // cout<<"en->"<<en<<endl;
            found=1;
            int ln=en-start+1;
            cout<<ln<<endl;
            // cout<<cards[en]<<" "<<ln<<" "<<mp[cards[en]]<<endl;
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