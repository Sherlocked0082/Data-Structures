//Good Question:
//Method 1 .sliding window variable size
// slide window  and take the max
//first try all the left B elemens
int pick(vector<int> &A, int B) {
    int n=A.size();
    int mxsum=0,sum=0;
    for(int i=0;i<B;i++)
        sum+=A[i];
    mxsum=sum;
    
    int left=B-1,right=n-1;
    while(left>=0 && right>=0)
    {
        sum+=A[right--];
        sum-=A[left--];
        
        mxsum=max(mxsum,sum);
    }
    return mxsum;
}
//Sliding Window from both sides
// 1  2  3  4  5  6  7
//<--------->
//-------->        <--  
//------>        <----
//---->        <------
//-->        <--------


//Method 2:
int maxScore(vector<int>& cardPoints, int k) {
    int ans,sum=0,n=cardPoints.size(),currwin=0;
    
    for(int i=0;i<n;i++)
        sum+=cardPoints[i];
    for(int i=0;i<n-k;i++)
        currwin+=cardPoints[i];
    ans=sum-currwin;
    for(int i=n-k;i<n;i++)
    {
        currwin+=(cardPoints[i]-cardPoints[i-n+k]);
        ans=max(ans,sum-currwin);
    }
    return ans;
}

//--------------------------------------------------------------------------------------------------
//Variation 1:
//Google Kickstart Round D 10 July22
//QSummary:Given 2 arrays pick k elements from left and right such that sum is maximum
//https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caea6/0000000000b76fae

//Solution:
ll pick(vector<ll> &A, ll B) {
    ll n=A.size();
    if(B==0 || B>n)
        return 0;
    ll mxsum=0,sum=0;
    for(ll i=0;i<B;i++)
        sum+=A[i];
    mxsum=sum;
    ll left=B-1,right=n-1;
    while(left>=0 && right>=0)
    {
        sum+=A[right--];
        sum-=A[left--];
        
        mxsum=max(mxsum,sum);
    }
    return mxsum;
}

void solve(int t) {
    cout<<"Case #"<<t<<": ";
    int n;
    cin>>n;
    vector<ll> va(n);
    for(int i=0;i<n;i++)
        cin>>va[i];
    int m;
    cin>>m;
    vector<ll> vb(m);
    for(int i=0;i<m;i++)
        cin>>vb[i];
    int k;
    cin>>k;
    ll ans=0;
    for(int i=0;i<=k;i++)//
    {
        ans=max(ans,(pick(va,i))+(pick(vb,k-i)));
    }
    cout<<ans<<"\n";
}


//Mock Interview
//Tried to explain:
//k=3
//  8   6   1   2   3   4
//---------->  sum=14 
//------->    sum=18  <--
//-->   sum=18    <------
//   sum=9    <-----------  
//ans-> 18 

//Steps:
//1.Find the sum of first k elements
//2.Slide the window (decrease window size from left and increase window size from right)
//3.Keep track of max sum obtained while sliding the window

//Step 1:Time->O(k)     Space->O(1)
//int currsum=0;
//for(int i=0;i<k;i++)
    // currsum+=A[i];

//Step 2:Time->O(k)
//int ans=INT_MIN,left=k-1,right=n-1;
//while(left>=0 && right>=0)
// {
    // currsum-=A[left--];
    //currsum+=A[right--];
    // ans=max(ans,currsum);
// }

//Step 3:
//return ans;

//Overall Time Complexity->O(k)
//Space Complexity -> O(1)

//Lastly Try to explain a Edge Case or Corner Case{if able to generate:)} while going with flow of your algorithm
//A={20,4,1,8,10,11}    k=4;
 //--------->       33
 //------->     <-- 36
 //----->    <----- 45
 //--->   <-------- 49
 //      <--------- 30