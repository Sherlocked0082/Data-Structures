#include <bits/stdc++.h>
using namespace std;

void print_span(int A[],int n)
{
    stack<int> s;//will hold the indexes
    s.push(0);
    cout<<"1 ";
    int span;
    for(int i=1;i<n;i++){
        while(s.empty()==false && A[s.top()] <=A[i])
        {
            s.pop();
        }
        span=s.empty()?i+1:i-s.top();
        cout<<span<<" ";
        s.push(i);
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
    print_span(A,n);
	return 0;
}