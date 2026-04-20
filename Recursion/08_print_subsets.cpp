#include<bits/stdc++.h>
using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op;//initialize with previous output
    string op2=op;
    //we dont add anything to op1 as no character is taken in consideration(check tree)
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    solve(ip,op1);
    solve(ip,op2);
}
int main()
{
    string s;
    cout<<"Enter string\n";
    cin>>s;
    string op="";
    solve(s,op);

}