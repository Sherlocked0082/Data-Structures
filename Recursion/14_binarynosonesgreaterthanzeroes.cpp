#include<bits/stdc++.h>
using namespace std;

void solve(int one,int zero,int n,string op)
{
    if(n==0)//base condition
    {
        cout<<op<<endl;
        return;//imp to avoid segmentation fault
    }

    string op1=op;//there is always a choice for 1
    op1.push_back('1');
    solve(one +1,zero,n-1,op1);

    if(one>zero)//choice for zero
    {
        string op2=op;
        op2.push_back('0');
        solve(one,zero+1,n-1,op2);
    }
    return;
}
int main()
{
    int n;
    cout<<"Enter n\n";
    cin>>n;
    string op="";
    int one=0,zero=0;
    solve(one,zero,n,op);

}

/*
Given a positive integer N, print all N bit binary numbers having more 1’s than 0’s for any prefix of the number.
Input:
2
2
3
Output:
11 10
111 110 101

*/