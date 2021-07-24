#include <iostream>
using namespace std;
int flipbit(int n , int i)
{
    int result = n^(1<<i);
    return result;
}
int main() 
{   //flip the ith bit
    int n , i;
    cin>>n>>i;
    cout<<flipbit(n,i)<<endl;
	return 0;
}
