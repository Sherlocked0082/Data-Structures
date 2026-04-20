


//Medium variation
//https://leetcode.com/contest/biweekly-contest-91/problems/count-ways-to-build-good-strings/
long long MOD=1e9+7;
int countGoodStrings(int low, int high, int zero, int one) {
    int ans=0;
    vector<int> dp(high+1,0);
    //dp[i]->number of ways to make string of length i
    dp[0]=1;
    for(int i=1;i<=high;i++)
    {
        if(i>=zero)
            dp[i]=(dp[i]+(dp[i-zero]%MOD))%MOD;
        if(i>=one)
            dp[i]=(dp[i]+(dp[i-one]%MOD))%MOD;
    }
    for(int i=low;i<=high;i++)
    {
        ans=(ans+dp[i]%MOD)%MOD;
    }
    return ans;
}