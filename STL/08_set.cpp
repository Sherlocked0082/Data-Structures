#include<bits/stdc++.h>
using namespace std;
/*
Maps-Value=SETs ;)
sets is collection of keys(collection of some elements) 
Types of set
1.Normal set
2.Unordered sets
3.Multisets(very heavily used)
Properties
1.stores unique elements
2.stores in sorted order
3. time complexity ->same as map ->o(logn) 
*/

void print(set<string> &s)
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
    set<string> s;
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