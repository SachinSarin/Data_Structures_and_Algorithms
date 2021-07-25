//PRINTING ALL PRIMES NUMBER USING SIEVE METHOD IN (Nloglogn) Time
#include <iostream>
using namespace std;
#define max 1000006
void sieve(int prime[])
{
    prime[0]  = 0;
    prime[1] = 0;
    for(int i = 2; i*i < max; i++)
    {   
        if(prime[i]==1)
        {
            for(int j = i*i; j < max; j+=i)
            {
                prime[j]=0;
            }
        }
    }
    
    for(int i = 0; i < max; i++)
    {   if(prime[i]==1)
        {
           cout<<i<<endl;
        }
       
    }
}
int main() {
	// your code goes here
	int prime[max];
	for(int i = 0; i <max; i++ )
	{
	    prime[i] = 1;
	}
	
	sieve(prime);
	return 0;
}
