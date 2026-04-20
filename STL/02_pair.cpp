#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,string> p,p1;
    //input methods
    //1.make_pair
    p=make_pair(2,"abc");
    cout<<p.first<<" "<<p.second<<"\n";
    //method 2
    p={2,"abc"};
    cout<<p.first<<" "<<p.second;
    //we can also copy pairs
    p1={12,"abcd"};
    pair<int,string> temp=p1;
    cout<<temp.first<<" "<<temp.second<<"\n";//here copy is made
    

    return 0;
}