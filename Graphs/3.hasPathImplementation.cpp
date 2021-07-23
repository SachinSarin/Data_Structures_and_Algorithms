/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.


//INPUT FORMAT
First line will contain T(number of test cases), each test case as follow.
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

//OUTPUT FORMAT
true or false for each test case in a newline.

//CONTRAINTS
1 <= T <= 10
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
1
4 4
0 1
0 3
1 2
2 3
1 3
true




*/


#include<bits/stdc++.h>
using namespace std;
bool haspath(int** edges , bool* visited , int start , int end , int n)
{
		//base case
    	if(start==end)
        {
            return 1;
        }
    	int result = 0;
    	
    	for(int i = 0; i < n; i++)
        {
			if(edges[start][i]==1&&!visited[i])
            {	visited[i] = true;
				result = haspath(edges,visited,i,end,n);
             	if(result==1)
                {
                    return 1;
                }
            }
        }
    
    return result;
    
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
		int n , e;
        cin>>n>>e;
        bool* visited = new bool[n];
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        
        int** edges = new int*[n];
        for(int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for(int  j = 0; j < n; j++)
            {
                edges[i][j] =  0;
            }
            
        }
        
        for(int i = 0; i < e; i++)
        {
			int f , s;
            cin>>f>>s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        
        int c , d ;
        cin>>c>>d;
        int result = 0;
        if(haspath(edges,visited,c,d,n))
        {
            cout<<"true"<<endl;
            
        }
        else
        {  
         	cout<<"false"<<endl;
         }
    }
    return 0;
}
