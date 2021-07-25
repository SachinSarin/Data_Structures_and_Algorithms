/*
A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6

You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
Input Format:
Contain an integer N

Output Format:
Print the number of super prime between [1, N]
Constraints:
1 <= N <= 10^6
Sample Input 1:
10
Sample Output 1:
2
Sample Input 2:
25
Sample Output 2:
10
Explanation:
The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.
*/

#include<bits/stdc++.h>
using namespace std;
int solve(int n)
{
    bool isprime[n+1];
    memset(isprime,true,sizeof(isprime));
    int primecount[n+1];
    memset(primecount,0,sizeof(primecount));
    for(int i = 2; i<=n; i++)
    {
        if(isprime[i] == true)
        {
			for(int j = 2; j*i <=n; j++)
            {
				isprime[i*j] = false;
                primecount[i*j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <=n; i++)
    {
        if(primecount[i]==2)
        {
            ans++;
        }
    }
    return ans;
}
int main(){
    
    // write your code here
    int n ;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
