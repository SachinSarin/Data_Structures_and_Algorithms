#include <iostream>
using namespace std;
int solve(int n , int i,int operation)
{   int result;
    if(operation ==1 )
    {
        
        result = n<<i;
    }
    if(operation==0)
    {
        result = n>>i;
    }
    return result;
}
int main() {
//Implementation of left shift and right shift of the operator;
	int n,i,operation;
	cin>>n; //represent number that should be left or right shifted
	cin>>i; //i denotes how many times number should be left shifted or right shighted
    cin>>operation; // two case left shift or right shift
	cout<<solve(n,i,operation)<<endl;
	return 0;
}
