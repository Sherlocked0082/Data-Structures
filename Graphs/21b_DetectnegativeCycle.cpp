// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n,100000000);
	    for(int i=1;i<=n-1;i++)
	    {
	        for(int k=0;k<edges.size();k++)
	        {
	            int u=edges[k][0];
	            int v=edges[k][1];
	            int wt=edges[k][2];
	            
	            if(dist[v]>dist[u]+wt)
	                dist[v]=dist[u]+wt;
	        }
	    }
	    
	    for(int k=0;k<edges.size();k++)
        { 
	            int u=edges[k][0];
	            int v=edges[k][1];
	            int wt=edges[k][2];
            
            if(dist[v]>dist[u]+wt)
                return 1;
        }
        return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends