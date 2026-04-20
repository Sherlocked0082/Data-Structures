//O(n) Naive:
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n),suff(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]*nums[i];
        }
        
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suff[i]=suff[i+1]*nums[i];
        }
        
        vector<int> ans;
        ans.push_back(suff[1]);
        for(int i=1;i<n-1;i++)
        {
            ans.push_back(suff[i+1]*pre[i-1]);
        }
        ans.push_back(pre[n-2]);
        
        return ans;
    }



//O(1) Optimised
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        
        int start=1,end=1;
        
        for(int i=0;i<n;i++)
        {
            ans[i]*=start;
            start*=nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=end;
            end*=nums[i];
        }
        
        return ans;
    }

