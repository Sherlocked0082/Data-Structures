#include<bits/stdc++.h>
using namespace std;
//DO MOre Variations On these Problems
struct Stack
{
    queue<int> q1,q2;
    int top()
    {
        return q1.front();
    }
    int size()
    {
        return q1.size();
    }
    int pop()
    {
        return q1.front();
    }
    void push(int x)
    {
        while(q1.empty()==false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.empty()==false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

int main()
{
    	Stack s; 
	s.push(10); 
	s.push(5); 
	s.push(15); 
	s.push(20);

	cout << "current size: " << s.size() << endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 

	cout << "current size: " <<  s.size() << endl; 
	return 0; 
    
    return 0;
}