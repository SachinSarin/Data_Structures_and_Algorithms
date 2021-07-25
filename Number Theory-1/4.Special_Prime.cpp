/*
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1

Neighbouring primes are prime number such that there is no other prime number between them.

Input Format:
An integer N.

Output Format:
Print the number of special primes
Constraints:
1 <= N <= 2*10^5
Sample Input:
27
Sample Output:
2
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    int n;
    cin>>n;
    bool isprime[n+2];
    memset(isprime,true,sizeof(isprime));
    vector<int> primelist;
    //apply sieve
    for(int i = 2; i<=n; i++)
    {
        if(isprime[i])
        {
            for(int j =2; j*i < n+1; j++ )
            {
                isprime[i*j] = false;
            }
        }
    }
    
    for(int i = 2; i <=n; i++)
    {
        if(isprime[i])
        {
			primelist.push_back(i);
        }
    }
    
    int count = 0;
    for(int i = 1; i<primelist.size(); i++)
    {
        int a = primelist[i] + primelist[i-1]+1;
        if(a<=n && isprime[a])
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
