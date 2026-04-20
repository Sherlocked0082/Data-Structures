#include <bits/stdc++.h>
using namespace std;
//There are 4 standard variations on this type NSR,NGR,NSL,NGL

//Naive:
//Traverse through all elements and for every element go through left of it and find 
//the first element greater than currElement 


//Optimised
//Variation of stock span O(n)
//when an item is processed check whether top of stack is smaller than this 
//
//18 12 13 14 11 16
void previous_greater_element(int A[],int n)
{
    stack<int> s;
    s.push(A[0]);
    cout<<-1<<" ";
    for(int i=1;i<n;i++)
    {
        while(s.empty()==false && s.top()<A[i])
        {
            s.pop();
        }
        int prev_great=s.empty()?-1:s.top();
        cout<<prev_great<<" ";
        s.push(A[i]);
    }
}


int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }    
    previous_greater_element(A,n);

	return 0;
}