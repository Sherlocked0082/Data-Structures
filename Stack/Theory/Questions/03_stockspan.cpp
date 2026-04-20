#include <bits/stdc++.h>
using namespace std;

/*
Observations->
1.
If there is a greater element then
1.span=index of current element - index of closest greater element on left
if there is no greater element the span is index+1


2.IMP:
we need to store 
1.element that we just processed
2.previous greater of this element 
3.and previous greater of that element and so on
and we need to store them in LIFO order 
*/
//Naive:
//For every elemetn go back to it and check first greater elemetn than this 



//Optimised
//TIme-> O(n)
//Spce->O(n)

//Stop at nearest greater to left
void span(int n, int A[])
{
    stack<int> s;
    s.push(0);//push the index
    cout<<"1 ";
    for(int i=1;i<n;i++)
    {   //here we are removing all the items from top of stack which are smaller or less than the current item
        while(s.empty()==false && A[s.top()]<=A[i])
        {
            s.pop();
        }
        int span=s.empty()?i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);//pushing the index of curr item 
    }
}
int main() {
    
	return 0;
}


//Daily temp leetcode -> Reverse Stock Span
// https://leetcode.com/problems/daily-temperatures/
vector<int> dailyTemperatures(vector<int>& temperatures) {//reverse stock span
    vector<int> ans;
    stack<int> st;//storing indexes
    for(int i=temperatures.size()-1;i>=0;i--)
    {
        while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            st.pop();
        st.empty()? ans.push_back(0):ans.push_back(st.top()-i);
        
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}