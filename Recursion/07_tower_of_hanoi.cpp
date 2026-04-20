#include<bits/stdc++.h>
using namespace std;

void solve(int n,int s,int d,int h,int &count)
{
    count++;//to calculate number of steps
    if(n==1)//Base condition
    {
        cout<<"Move Plate "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    //----------------------------------------------------------
    //Hypothesis
    solve(n-1,s,h,d,count);//move n-1 plates(one by one) from source to helper 
    cout<<"Move Plate "<<n<<" from "<<s<<" to "<<d<<endl;//
    solve(n-1,h,d,s,count);
    return;

}
int main()
{
    cout<<"Enter no of Plates\n";
    int n,count=0;
    cin>>n;
    int s=1,h=2,d=3;
    
    solve(n,s,d,h,count);
    cout<<"\nThe number of steps to do this is "<<count;
}