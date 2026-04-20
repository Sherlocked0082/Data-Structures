#include <bits/stdc++.h> 
using namespace std; 
#define V 4
/*
This is naive and simple implementation 
using matrix representation
time->O(V*V)
*/

//Here we can do this optimised by using priority queue
vector<int> djikstra(int graph[V][V], int source)
{
    vector<int> dist(V,INT_MAX);
    dist[source]=0;
    vector<bool> finalised(V,false);

    for(int count=0;count<V-1;count++)
    {
        int u=-1;

        for(int i=0;i<V;i++)
        {
            if(!finalised[i] && (u==-1 || dist[i]<dist[u]))
                u=i;
        }
        finalised[u]=true;

        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=0 && finalised[v]==false)
            {
                dist[v]=min(dist[v],dist[u] + graph[u][v]);
            }
        }
    }
    return dist;
}

int main() 
{ 
	int graph[V][V] = { { 0, 50, 100, 0}, 
						{ 50, 0, 30, 200 }, 
						{ 100, 30, 0, 20 }, 
						{ 0, 200, 20, 0 },}; 

	for(int x: djikstra(graph,0)){
	    cout<<x<<" ";
	} 

	return 0; 
} 

/*
C52
To find out the PAth 
Have another array lets say pred array in which we maintain the predesor of Node
when we calculate the distance from Node u to any vertex at that point what is just previous Node in the PAth
maintain that
Initially Predesor of every Node is surce vertex(u) as there exist a direct edge bw source and the Node
And when we are changing distance of Node V pred[v] must be changed to W bcas edge w-v is smaller than edge V-u

Now we have populated array pred 
How to construct path from Node u to V
U , ....Pred[pred[w]]  pred[W]   w   v
store in stack and then pop them out 

WHy Negative wths are not allowed
Finalize conditin
The Least weighted edge going out of source node is the edge to be finalized this observation will itself not worl if negative 
edge is allowed and if this observation does not work we cannot use this edge to finalize other edges 
so negative weights are not allowed in DSPA

Issues with negativee cycles TBD
Total weight happens to eb negative ...

PROOF->
Q1.WHy 


*/