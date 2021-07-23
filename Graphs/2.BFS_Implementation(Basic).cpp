#include <iostream>
#include <queue>
using namespace std;
void bfs(int** edges , bool* visited , int start , int n , int e)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(q.empty()==false)
    {
        int currentvertex = q.front();
        cout<<currentvertex<<endl;
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(edges[currentvertex][i]==1&&!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main() {
	//implementing bfs 
	int n , e;
	cin>>n>>e;
	// n denotes number of vertices and e denotes number of edges
	bool* visited = new bool[n];
	for(int i = 0; i < n; i++)
	{
	    visited[i] = false;
	}
	//creating a array which contains edges
	int** edges = new int*[n];
	for(int i = 0; i < n; i++)
	{
	    edges[i] = new int[n];
	    for(int j = 0;  j < n; j++)
	    {
	        edges[i][j] = 0;
	    }
	}
	
	//fill the graph path 
	for(int i = 0; i < e; i++)
	{
	    int f ,s ;
	    cin>>f>>s;
	    edges[f][s] = 1;
	    edges[s][f] = 1;
	}
	bfs(edges,visited,0,n,e);
	return 0;
}
