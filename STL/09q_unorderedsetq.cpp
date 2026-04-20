#include<bits/stdc++.h>
using namespace std;
/*
given q queries find wheteher it is present or not
*/
void print(unordered_set<string> &s)
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
    unordered_set<string> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.insert(str);
    }    
    int q;
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;
        if(s.find(str)==s.end())
        {
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
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
3
abc
ghi
abcdef
*/