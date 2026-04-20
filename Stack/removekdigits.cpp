class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
            return "0";
        if(k==0)
            return num;
        stack<char> st;
        for(int i=0;i<num.size();i++)
        {
            while(k && !st.empty() && st.top()>num[i])
            {
                k--;
                st.pop();            
            }
            st.push(num[i]);
            if(st.size()==1 && st.top()=='0')
                st.pop();
        }
        while(k && !st.empty())//VIMP when 123456 k=3 here we will remove last 3 ans=123
        {
            k--;
            st.pop();
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)
            ans="0";
        return ans;
    }
};