#include <iostream>
using namespace std;
int checkbit(int n , int i)
{
    int result = n&(1<<i);
    return result;
}
int main() {
    //check if the bit is set or not
	int n , i;
	cin>>n;
	cin>>i;
	int result = checkbit(n,i);
	if(result!=0)
	{
	    cout<<"set"<<endl;
	}
	else
	{
	    cout<<"unset"<<endl;
	}
	return 0;
}
