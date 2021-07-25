/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?

Input Format :
First line will contain T(number of test cases), each test case follows as.
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake

Output Format :
Print the size of the biggest piece of '1's and no '0'sfor each test case in a newline.
Constraints:
1 <= T <= 10
1 <= N <= 1000
Sample Input :
1
2
11
01
Sample Output :
3

*/
#include<bits/stdc++.h>
using namespace std;
void cake(bool** visited , int** edges , int row , int col ,int n , int&count)
{


	//margin conditions
    if(row < 0 || col < 0 || row>=n || col >= n || edges[row][col]==0 ||visited[row][col]==true)
    {
		return;
    }
    
    //final conditions
    
    count++;
    if(row==n-1&&col==n-1)
    {
        if(edges[row][col]==1)
        {
            visited[row][col]==1;
        }
    }
    //recursive calls condition
    visited[row][col] = true;
    cake(visited,edges,row-1,col,n,count);
    cake(visited,edges,row+1,col,n,count);
    cake(visited,edges,row,col-1,n,count);
    cake(visited,edges,row,col+1,n,count);

}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool** visited = new bool*[n];
        for(int i = 0; i < n; i++)
        {
            visited[i] = new bool[n];
            for(int j = 0; j < n; j++)
            {
                visited[i][j] = false;
            }
        }
        int** edges = new int*[n];
        for(int i = 0; i < n; i++)
        {
            edges[i] = new int[n];
            for(int j= 0; j < n; j++)
            {
                edges[i][j] = 0;
            }
        }
        string str;
        for(int i = 0; i < n; i++)
        {
            cin>>str;
            for(int j = 0; j < n; j++)
            {
                   if(str[j]=='0')
           		 {
					edges[i][j] = 0;
            	}
                if(str[j]=='1')
                {
                    edges[i][j] = 1;
                }
            }
         
            
        }
        
        int result = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(edges[i][j]!=1)
                {
					continue;
                }
                int count = 0;
                cake(visited,edges,i,j,n,count);
                result = max(result , count);
            }
        }
        cout<<result<<endl;
    }

    return 0;
}
