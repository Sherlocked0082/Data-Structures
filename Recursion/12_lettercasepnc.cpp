#include<bits/stdc++.h>
using namespace std;

void solve(string ip,string op,vector<string> &ans)
{
    if(ip.length()==0)
    {
        ans.push_back(op);
        return;
    }

    if(isalpha(ip[0]))
    {
        string op1=op;
        string op2=op;

        op1.push_back(tolower(ip[0]));//2 choices so 2 op
        op2.push_back(toupper(ip[0]));
    
        ip.erase(ip.begin() + 0);
        solve(ip,op1,ans);
        solve(ip,op2,ans);
    }
    else//if it is a number
    {
        string op1=op;
        op1.push_back(ip[0]);//one choice so 1 op

        ip.erase(ip.begin() + 0);
        solve(ip,op1,ans);
    }
    return;
}

vector<string> letterCasePermutation(string s) {
    string ip=s;
    string op="";
    vector<string> ans;
    solve(ip,op,ans);
    return ans;
}

int main()
{
    cout<<"Enter string\n";
    string ip;
    cin>>ip;
    vector<string> ans=letterCasePermutation(ip);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

}