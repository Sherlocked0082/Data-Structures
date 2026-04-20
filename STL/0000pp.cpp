#include<bits/stdc++.h>
#define ll long long 
#define lld long double
#define deb(x) cout << #x << " = " << x << endl
using namespace std;

vector<string> removeDupWord(string str)
{
    vector<string> ans;
    string word = "";
    for (auto x : str) 
    {
        if (x == ' ')
        {
            ans.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
    }
    ans.push_back(word);
    return ans;
}
vector<string> missingword(string s,string t)
{
    vector<string> sv=removeDupWord(s);
    vector<string> tv=removeDupWord(t);
    vector<string> ans;
    int j=0;
    for(int i=0;i<sv.size();i++)
    {
        if(sv[i]!=tv[j])
        {
            ans.push_back(sv[i]);
        }
        else
            j++;
    }
    return ans;
}
int main()
{
    string s,p;
    getline(cin,s);
    getline(cin,p);
    int i=0;
    string a;
    
    vector<string> ans=missingword(s,p);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}