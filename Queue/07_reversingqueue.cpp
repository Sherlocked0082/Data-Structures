#include<bits/stdc++.h>
using namespace std;
void reverse_iterative(queue<int> &q1)
{
    stack<int> s;
    while(q1.empty()==false)
    {
        s.push(q1.front());
        q1.pop();
    }
    while(s.empty()==false)
    {
        q1.push(s.top());
        s.pop();
    }
}
void reverse_recursive(queue<int> &q1)
{
    if(q1.empty())
        return;
    int x=q1.front();
    q1.pop();
    reverse_recursive(q1);
    q1.push(x);

}
void Print(queue<int>& Queue) 
{ 
	while (!Queue.empty()) { 
		cout << Queue.front() << " "; 
		Queue.pop(); 
	} 
} 

int main()
{
    queue<int> q1;
    q1.push(12); 
	q1.push(5); 
	q1.push(15);
	q1.push(20); 

	// reverse_iterative(q1); 
	// Print(q1);
    // cout<<endl;
    reverse_recursive(q1); 
	Print(q1); 
    return 0;
}