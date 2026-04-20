//VIMP QUUS
#include<bits/stdc++.h>
using namespace std;
//Given a number n, print first n number(in increasing order) such that all these numbers have digits in set {5, 6}
void printFirstN(int n)
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for(int i=0;i<n;i++)
    {
        string curr=q.front();
        cout<<q.front()<<" ";
        q.pop();
        q.push(curr+"5");
        q.push(curr+"6");
    }
    //o(n);
    //we can handle large numbers and do it in efficient way

}
int main()
{
    int n;
    cin>>n;
    printFirstN(n);  
    return 0;
}