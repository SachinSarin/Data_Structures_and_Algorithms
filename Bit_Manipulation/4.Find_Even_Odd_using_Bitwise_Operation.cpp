#include <iostream>
using namespace std;
int even_odd(int n)
{
    int result = (n&1);
    return result;
}

int main() {
	//find number even and odd bitwise
	int n;
	cin>>n;
	int result = even_odd(n);
	if(result ==0)
	{
	    cout<<"Even"<<endl;
	}
	else
	{
	    cout<<"Odd"<<endl;
	}
	return 0;
}
