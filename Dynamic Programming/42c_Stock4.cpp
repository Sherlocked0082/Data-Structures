#include<bits/stdc++.h>
using namespace std;

//variation 4:Atmost k transactions allowed

//Recursion version
//M1:Memoization
int solve(int idx,int buy,vector<int> &prices,int cap,vector<vector<vector<int>>> &dp)
{
    if(idx==prices.size() || cap==0)
        return 0;
    
    if(dp[idx][buy][cap]!=-1)
        return dp[idx][buy][cap];
    if(buy)
    {
        dp[idx][buy][cap]=max(-prices[idx]+solve(idx+1,0,prices,cap,dp),solve(idx+1,1,prices,cap,dp));
    }
    else
    {
        dp[idx][buy][cap]=max(+prices[idx]+solve(idx+1,1,prices,cap-1,dp),solve(idx+1,0,prices,cap,dp));

    }
    return dp[idx][buy][cap];
}
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>> (2,vector<int> (k+1,-1)));
    return solve(0,1,prices,k,dp);
}
//M2:Tabulation
int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>> (2,vector<int> (k+1,0)));

    //Base Case: No need, already initialized with 0
    for(int idx=n-1;idx>=0;idx--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=k;cap++)
            {
                if(buy)
                {
                    dp[idx][buy][cap]=max(-prices[idx]+dp[idx+1][0][cap],dp[idx+1][1][cap]);
                }
                else
                {
                    dp[idx][buy][cap]=max(+prices[idx]+dp[idx+1][1][cap-1],dp[idx+1][0][cap]);

                }           
            }
        }
    }

    return dp[0][1][k];
}
int main(){
    int n,k;
	cin>>n>>k;
	vector<int> prices(n);
	for(int i=0;i<n;i++)
        cin>>prices[i];
    // cout<<StockBuySell3(prices)<<endl;
    cout<<f(0,1,prices,2,k)<<endl;
    return 0;
}

