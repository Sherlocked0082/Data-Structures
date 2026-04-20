


//Case 3:Infinite Transactions + Fees(IMP Anlysis)
//maintain 2 states  1.have one stock extra on each y 2.have sell all the stocks 
 int StockBuySell3(vector<int>& prices, int fee) {
        int n=prices.size();
        int buystateprofit=-prices[0];//brought the stock on day[0]
        int soldstateprofit=0;//nothing to sell
        
        for(int i=1;i<n;i++)
        {
            buystateprofit=max(buystateprofit,soldstateprofit-prices[i]);//max of 
            soldstateprofit=max(soldstateprofit,buystateprofit+prices[i]-fee);//assume the fee is applied while selling the stock
        }
        return soldstateprofit;
}

//Method 2:memoization
int solve(int idx,int buy,vector<int> &prices,int fee,vector<vector<int>> &dp)
{
    if(idx==prices.size())
        return 0;
    
    if(dp[idx][buy]!=-1)
    {
        return dp[idx][buy];
    }
    if(buy)
    {
        dp[idx][buy]=max(-prices[idx]+solve(idx+1,0,prices,fee,dp),solve(idx+1,1,prices,fee,dp));
    }
    else
    {
        dp[idx][buy]=max(prices[idx]+solve(idx+1,1,prices,fee,dp)-fee,solve(idx+1,0,prices,fee,dp));
    }
    return dp[idx][buy];
}


//Method 3:Tabulation
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    dp[n][0]=0,dp[n][1]=0;
    for(int idx=n-1;idx>=0;idx--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit=0;
            if(buy)
            {
                dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
            }
            else
            {
                dp[idx][buy]=max(prices[idx]+dp[idx+1][1]-fee,dp[idx+1][0]);
            }       
        }
    }
    return dp[0][1]; 
}