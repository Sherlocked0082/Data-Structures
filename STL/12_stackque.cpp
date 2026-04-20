#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main() 
{ 
    queue<string> q;//FIFO
    q.push("abc");
    q.push("def");
    q.push("ghi");
    q.push("jkl");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
	
}