#include <bits/stdc++.h>
using namespace std;

int postfix_evaluation(string s)
{
    stack<int> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');//s[i]is character so we need to convert it into int
            //so whenever u subtract ascii value of 0 from any charter it becomes int
        }
        else
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}
int main() {
    cout<<postfix_evaluation("1023^^");
    return 0;
}
//"46+2/5*7+"