#include<bits/stdc++.h>
using namespace std;
class trieNode
{   public:
    trieNode* left;
    trieNode* right;
};

void insert(int n , trieNode* head)
{
    trieNode* curr = head;
    for(int i = 31; i>=0; i--)
    {
        int b = (n>>i)&1;
        //most important part
        if(b==0)
        {
            if(!curr->left)
            {
                curr->left = new trieNode();   
            }
            curr = curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
        
    }
}

int findmaxPair(trieNode* head , int*arr, int n)
{
    int max_xor = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int value = arr[i];
        trieNode* curr = head;
        int curr_xor = 0;
        for(int j = 31; j>=0; j--)
        {
            int b = (value>>j)&1;
            if(b==0)
            {
                if(curr->right)
                {   curr_xor += pow(2,j);
                    curr = curr->right;
                }else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if(curr->left)
                {    curr_xor += pow(2,j);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
            if(curr_xor > max_xor)
            {
                max_xor = curr_xor;
            }
        }
        
    }
    return max_xor;
}
int main() {
	// your code goes here
	int arr[6] ={8,1,12,15,10,5};
	trieNode* head= new trieNode();
	for(int i = 0; i < 6; i++)
	{
	    insert(arr[i],head);
	}
	cout<<findmaxPair(head,arr,6);
	return 0;
}
