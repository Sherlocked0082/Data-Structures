#include <bits/stdc++.h>
using namespace std;

bool match(char a,char b)
{
    return ((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'));
}

bool isbalance(string s)
{
    stack<char> ans;
    for(int i=0;i<s.size();i++)
    {
        if((s[i]=='(')||(s[i]=='{')||(s[i]=='['))
        {
            ans.push(s[i]);
        }
        else
        {
            if(ans.empty()==true)//for cases which starts from closing bracket 
                return false;
            else if(match(ans.top(),s[i])==false)
                return false;
            else
                ans.pop();
        }
    }
    return (ans.empty()==true);
}
int main() {
    string s;
    cin>>s;
    if(isbalance(s))
        cout<<"BAlanced";
    else
        cout<<"Not Balanced";
	return 0;
}