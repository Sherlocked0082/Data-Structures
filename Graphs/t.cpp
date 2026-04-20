#include<bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
{
	int dx[8]={-2,-1,1,2,2,1,-1,-2};
	int dy[8]={1,2,2,1,-1,-2,-2,-1};
	
	int sx=KnightPos[0];
	int sy=KnightPos[1];
	
	int tx=TargetPos[0];
	int ty=TargetPos[1];
	
	int visited[N+1][N+1];//visited array
	memset(visited,0,sizeof(visited));//initialize with 0
	
	int distance[N+1][N+1];
		memset(distance,0,sizeof(distance));
		
	queue<pair<int,int> >q;
	q.push({sx,sy});
	visited[sx][sy]=1;
	distance[sx][sy]=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<8;i++)
		{
			int nx= x + dx[i];
			int ny= x + dy[i];
			
			if(nx<0 || ny<0 || nx>N || ny>N || visited[nx][ny])
				continue;
			
			distance[nx][ny]=distance[x][y] + 1;
			visited[nx][ny]=1;
			q.push({nx,ny});
			
			if(nx==tx && ny==ty)
				return (distance[nx][ny]);
		}
		
	}
	return 0; 
	
}	
int main()
{

    return 0;
}