/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.


Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :
Path from v1 to v2 in reverse order (separated by space) for each test case in new line.

Constraints :
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
1
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
1
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(bool* visited , int** edges , int n, int sv , int ev)
{
	queue<int> q;
    q.push(sv);
    unordered_map<int,int> mp;
    bool done = false;
    while(q.empty()==false)
    {
        int currentvertex = q.front();
        q.pop();
		for(int i = 0; i < n; i++)
        {
        	if(edges[currentvertex][i]==1&&!visited[i]&&!done)
            {
                mp[i] = currentvertex;
                visited[i] = true;
                q.push(i);
                if(i==ev)
                {
                    done = true;
                    break;
                }
            }
        }
    }
    
    vector<int> output;
    if(!done)
    {
		return output;
    }
    
    int current = ev;
    output.push_back(ev);
    while(current!= sv)
    {
        current = mp[current];
        output.push_back(current);
    }
    return output;
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
		int n ,e ;
        cin>>n>>e;
        bool*visited = new bool[n];
        for(int i = 0; i<  n; i++)
        {
            visited[i] = false;
        }
        
        int** edges = new int*[n];
        for(int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for(int j = 0; j < n; j++)
            {
                edges[i][j] = 0;
            }
        }
        
        for(int i = 0; i < e; i++)
        {
            int f ,s ;
            cin>>f>>s;
            edges[f][s] =1;
            edges[s][f] = 1;
        }
        int v1 , v2;
        cin>>v1>>v2;
        vector<int> output = bfs(visited,edges,n,v1,v2);
        for(int i = 0; i < output.size(); i++)
        {
			cout<<output[i]<<" ";
        }
        cout<<endl;
        
	}
    return 0;
}
