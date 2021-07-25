/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 1 to V.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
For each test case and each connected components print the connected components in sorted order in new line.
Order of connected components doesn't matter (print as you wish).
Constraints :
2 <= V <= 10000
1 <= E <= 10000
Sample Input 1:
1
4 2
2 1
4 3
Sample Output 1:
1 2 
4 3 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> res;
vector<int> dfs(bool* visited , int** edges , int n , int start)
{
  
    visited[start] = true;
    res.push_back(start);
    for(int i = 1; i <= n; i++)
    {
        if(edges[start][i] ==1 && !visited[i] && i!=start)
        {
            visited[i] = true;

            dfs(visited , edges , n , i);
        }
    }
    return res;
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n , e;
        cin>>n>>e;
        bool* visited = new bool[n+1];
        for(int i = 1;i <=n; i++)
        {
            visited[i] = false;
        }
        int** edges = new int*[n+1];
        for(int i = 1; i <= n; i++)
        {
            edges[i] = new int[n+1];
            for(int j = 1; j <= n; j++)
            {
				edges[i][j] = 0;
            }
        }
        for(int i = 1; i <= e; i++)
        {
            int f , s;
            cin>>f>>s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        vector<vector<int>> result;
        for(int i = 1; i <=n; i++)
        {
            if(!visited[i])
            {
				vector<int> curr = dfs(visited,edges,n,i);
                sort(curr.begin(),curr.end());
                result.push_back(curr);
                res.clear();
            }
        }
        for(int i = 0; i < result.size(); i++)
        {
            for(int j = 0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";   
                
            }
            cout<<endl;
        }
    }
    return 0;
}
