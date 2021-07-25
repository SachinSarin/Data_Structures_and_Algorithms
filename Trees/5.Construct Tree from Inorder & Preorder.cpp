
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int pre_index = 0;
    Node* construct_Tree(int pre[] , int in[] , int start , int end , int n)
    {
        if(start>end)
        {
            return NULL;
        }
        int inindex;
        Node* root = new Node(pre[pre_index++]);
        for(int i = start; i <=end; i++)
        {
            if(in[i]==root->data)
            {
                inindex = i;
                break;
            }
        }
        root->left =  construct_Tree(pre,in,start,inindex-1,n);
        root->right = construct_Tree(pre,in,inindex+1,end,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int start = 0;
        int end = n-1;
        return construct_Tree(pre,in,start,end,n);
    }
};
