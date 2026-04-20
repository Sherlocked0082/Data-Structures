#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;//dynamic size array
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<int> v1(11);//11 size vector
    vector<int> v2(11,3);//11 size vector with all elemnts 3

    //coying of vector can be done
    vector<int> v2=v;//o(n) time complexity expensive
    return 0;
}
/*
//limitations
//1.if we declare vector/array locally maximum elements
which can be inserted are 10^5
2.if we declare vector/array globally limit is 10^7
*/