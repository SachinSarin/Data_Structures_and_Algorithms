#include <iostream>
using namespace std;
void dfs(int** edges , bool * visited , int start , int n  , int e)
{
     cout<<start<<endl;
    visited[start] = true;
    for(int i = 0; i < n; i++)
    {
        if(edges[start][i]==1&&!visited[i]&&i!=start)
        {
         
            dfs(edges,visited,i,n,e);
        }
    }
}
int main() {
	// dfs implementation
	int n , e;
	cin>>n>>e;
	// n denotes number of vertices and e denotes number of edges
	bool * visited = new bool[n];
	//creating a visited array for all vertices  intially all are false
	for(int i = 0; i < n; i++)
	{
	    visited[i] = false;
	}
	
	//make the edges array so that we can define  the edges between the points
	int** edges = new int*[n];
	for(int i = 0; i < n; i++)
	{
	    edges[i] = new int[n];
	    for(int j = 0; j < n; j++)
	    {
	        edges[i][j] = 0;
	    }
	}
	//define the edges 
	for(int i = 0; i < e; i++){
	    int f , s ;
	    cin>>f>>s;
	    edges[f][s] = 1;
	    edges[s][f] = 1;
	}
    // now apply dfs
    dfs(edges,visited,0,n,e);
	return 0;
}
