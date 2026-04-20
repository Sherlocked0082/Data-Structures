#include<bits/stdc++.h>
using namespace std;

//Variation 5:Colldown

//M2:Memoization
int solve(int idx,int buy,vector<int> &prices,vector<vector<int>> &dp)
{
    int n=prices.size();
    if(idx>=n)
        return 0;
    if(dp[idx][buy]!=-1)
        return dp[idx][buy];
    
    if(buy)
    {
        dp[idx][buy]=max(-prices[idx]+solve(idx+1,0,prices,dp),solve(idx+1,1,prices,dp));
    }
    else
    {
        dp[idx][buy]=max(+prices[idx]+solve(idx+2,1,prices,dp),solve(idx+1,0,prices,dp));
    }
    return dp[idx][buy];
}

//M3:Tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int> (2,0));

    for(int idx=n-1;idx>=0;idx--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            if(buy)
            {
                dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
            }
            else
            {
                dp[idx][buy]=max(+prices[idx]+dp[idx+2][1],dp[idx+1][0]);
            }     
        }
    }
    return dp[0][1];
}
//Space Optimization:



//-----------------------------------------------------------------------
//Another method
int StockBuySell4(vector<int>& prices) {
        int n=prices.size();
        int o_bsp=-prices[0],o_ssp=0,o_csp=0;
        for(int i=1;i<n;i++)
        {
            int n_bsp=0,n_ssp=0,n_csp=0;
            //buystateprofit
            if(o_csp-prices[i]>o_bsp)//selling 1 stock 
            {
                n_bsp=o_csp-prices[i];
            }else{
                n_bsp=o_bsp;
            }
            //sellstateprofit
            if(o_bsp + prices[i] > o_ssp)
            {
                n_ssp=o_bsp + prices[i];
            }else{
                n_ssp=o_ssp;
            }
            //collstateprofit
            if(o_ssp>o_csp)
            {
                n_csp=o_ssp;
            }else{
                n_csp=o_csp;
            }
            o_bsp=n_bsp;
            o_ssp=n_ssp;
            o_csp=n_csp;
        
        }
        return max(o_ssp,o_csp);
    }
// 3 ms	11.1 MB
int StockBuySell4(vector<int>& prices) {
        int n=prices.size();
        vector<int> bsp(n),ssp(n),csp(n);
        bsp[0]=-prices[0];
        ssp[0]=0;
        csp[0]=0;
        for(int i=1;i<n;i++)
        {
            bsp[i]=max(bsp[i-1],csp[i-1] - prices[i]);
            ssp[i]=max(ssp[i-1],bsp[i-1] + prices[i]);
            csp[i]=max(csp[i-1],ssp[i-1]);
        }
        return max(ssp[n-1],csp[n-1]);
}
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n==1)
    {
        return 0;
    }
    // vector<int> bsp(n),ssp(n),csp(n);
    int o_bsp,o_ssp,o_csp,bsp,csp,ssp;
    o_bsp=-prices[0];
    o_ssp=0;
    o_csp=0;

    for(int i=1;i<n;i++)
    {
        bsp=max(o_bsp,o_csp-prices[i]);
        ssp=max(o_ssp,o_bsp+prices[i]);
        csp=max(o_csp,o_ssp);

        o_bsp=bsp;
        o_ssp=ssp;
        o_csp=csp;
    }    
    return max(ssp,csp);
}





int main(){
    int n;
	cin>>n;
	vector<int> prices(n);
	for(int i=0;i<n;i++)
        cin>>prices[i];
    cout<<StockBuySell2(prices)<<endl;
    cout<<f(0,1,prices)<<endl;
    return 0;
}

