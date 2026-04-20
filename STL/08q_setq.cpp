#include<bits/stdc++.h>
using namespace std;
/*
find the unique strings
*/
void print(set<string> &s)
{
    cout<<s.size()<<endl;
    for(auto value : s)
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.insert(str);
    }    
    print(s);
    return 0;
}
/*i/p
8
abc
def
abc
ghi
jkl
ghi
ghi
abc
*/