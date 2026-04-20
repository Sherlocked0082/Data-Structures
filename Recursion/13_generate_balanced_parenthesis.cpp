#include<bits/stdc++.h>
using namespace std;

void solve(int open,int close,string op,vector<string> &ans)
{
    if(open==0 && close==0)
    {
        ans.push_back(op);
        return;
    }
    //we have to call op1 always untill it is not zero
    if(open!=0)
    {
        string op1=op;
        op1.push_back('(');
        solve(open-1,close,op1,ans);
    }
    //close bracket is only allowed if close>open
    if(close>open)
    {
        string op2=op;
        op2.push_back(')');
        solve(open,close-1,op2,ans);
    }
    return;
}

vector<string> generate_balanced_paranthesis(int n) {
    vector<string> ans;
    int close=n;
    int open=n;
    string op="";
    solve(open,close,op,ans);
    return ans;
}

int main()
{
    cout<<"Enter n\n";
    int n;
    cin>>n;
    vector<string> ans=generate_balanced_paranthesis(n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

}