#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixtopostfix(string s)
{
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++)
    {
        //first check whether it is operand or not
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            //we will pop untill we dont find a opening brackt
            while(!st.empty() && st.top()!='(')
            {
                res+=st.top();
                st.pop();
            }
            //Here checking if stack is empty or not and then poping out the opening bracket
            if(!st.empty())
            {
                st.pop();
            }
        }
        else//when operators are there
        //Here imp point is that the presedence of current operator must be greater than the top operator
        /*
        1.higher precedence then st top push to st
        2.Lower precedence pop st top and output until higher precendence operator is found.then push s to st
        3.Equal precedence use associativity 
        */
        {
            while(!st.empty() && (precedence(st.top()) >= precedence(s[i])))//Here equal case is important
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}
int main() {
    cout<<infixtopostfix("a*b/c");
    return 0;
}
//(a-b/c)*(a/k-l)