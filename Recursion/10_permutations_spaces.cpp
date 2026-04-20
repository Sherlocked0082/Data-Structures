#include<bits/stdc++.h>
using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }

    string op1=op;
    string op2=op;

    op1.push_back(' ');
    op1.push_back(ip[0]);

    op2.push_back(ip[0]);

    ip.erase(ip.begin() + 0);

    solve(ip,op1);
    solve(ip,op2);
    return;
}
int main()
{
    string ip;
    cout<<"Enter string\n";
    cin>>ip;
    string op="";
    //here we dont have any choice so do it in main function(ie we have no choice on includation of 1st character with space)
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    solve(ip,op);

}   