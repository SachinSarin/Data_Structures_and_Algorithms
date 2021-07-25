/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 0 to N - 1) and M pair of integers (u and v) denoting island, u is connected to island v and vice versa. Can you count the number of connected groups of islands?
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
Line 1: Two Integers N and M (separated by space)
Next 'E' lines, each have two space-separated integers, 'u' and 'v', denoting that there exists an edge between Vertex 'u' and Vertex 'v'.
Output Format:
Print number of Islands for each test case in new line.
Constraints:
1 <= T <= 10
1 <= N <= 1000
1 <= M <= min((N*(N-1))/2, 1000)
0 <= u[i] ,v[i] < N
Output Return Format :
The count the number of connected groups of islands
Sample Input :
1
2 1
1 2
Sample Output :
1 
*/
#include<bits/stdc++.h>
using namespace std;
void printdfs(int** edges , bool * visited , int start,int n)
{
    visited[start] = true;
    for(int i = 0; i < n; i++)
    {
        if(edges[start][i]==1 && !visited[i] && i!=start)
        {   
            printdfs(edges,visited,i,n);
           
            
        }
    }
}
int main(){
    
    // write your code here
    int count = 0;
    int t;
    cin>>t;
    while(t--)
    {
		int n , e;
        cin>>n>>e;
        bool * visited = new bool[n];
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int ** edges = new int*[n];
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
            int f , s;
            cin>>f>>s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        
        for(int i = 0; i < n;  i++)
        {
            if(!visited[i])
            {
                  count++;
            	  printdfs(edges,visited,i,n);
            }
          
            
        }
        cout<<count<<endl;
        count=0;
    }
    return 0;
}
