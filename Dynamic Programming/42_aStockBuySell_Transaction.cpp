
/*
Assume every day potential selling Day

*/
//Case1:One Transaction(https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
int StockBuySell1(vector<int>& prices) {
       //maxprofit=curr-mintillNow
        int n=prices.size(),ans=0;
        int mintillnow=prices[0];
        for(int i=1;i<n;i++)
        {
            ans=max(ans,prices[i]-mintillnow);
            mintillnow=min(mintillnow,prices[i]);
        }
        return ans;
}

//-----------------------------------------------------------------
//Case2:Infinite Transactions allowed
//NO overlapping allowe

//Collect all upstrokes whenver upstroke increment sd when dowstroke move sd and bd both
int StockBuySell2(vector<int>& prices) {
        int n=prices.size();
        int selling_date=0,buying_date=0,profit=0;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i]>=prices[i-1])
                selling_date++;
            else
            {
                profit+=prices[selling_date]-prices[buying_date];
                selling_date=i;
                buying_date=i;
            }
        }
        profit+=prices[selling_date]-prices[buying_date];//for the last upstroke(VIMP)
        
        return profit;
    }

//-----------------------------------------------------------------
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


//-----------------------------------------------------------------
//Case 3:Infinite Transactions + Cooldown
// 4 ms	11.2 MB
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

//--------------------------------------------------------------------------------------------
//Case 4:2 Transactions allowed
