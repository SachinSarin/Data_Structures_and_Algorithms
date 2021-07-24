#include <iostream>
using namespace std;
void find_power(int n)
{
    if(n&(n-1)==0)
    {
        cout<<"The Number is Power of 2"<<endl;
    }
    else
    {
        cout<<"The Number is Not a Power of 2"<<endl;
    }
}
int main() {
	//finding power of 2 in O(1)
	int n;
	cin>>n;
	find_power(n);
	return 0;
}
