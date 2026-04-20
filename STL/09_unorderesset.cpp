#include<bits/stdc++.h>
using namespace std;
/*
use this when order doesnt matters
like use it when it is only given to check whether the given value is present or not
the difference b/w sets and unoredered set is same as
the difference b/w map and unordered map
here hash tables are used 
here keys can be int long long string(simple data types)
we cant use vector pair etc
*/

void print(unordered_set<string> &s)
{
    cout<<s.size()<<endl;
    for(string value : s)
    {
        cout<<value<<endl;
    }
    // for(auto it=s.begin();it!=s.end();it++)
    // {
    //     cout<<(*it)<<endl;
    // }
    //Both are the same thing
}
int main()
{
    unordered_set<string> s;
    s.insert("abc");// log(n)
    s.insert("def");
    s.insert("xyz");
    //---------------------------------------------
    //finding the elemet
    auto it=s.find("abc");
    if(it!=s.end()){
        cout<<(*it)<<endl;
    }
    print(s);
    //---------------------------------------------
    //erase 
    s.erase("abc");
    return 0;
}