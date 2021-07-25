
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to check whether all nodes of a tree have the value 
//equal to the sum of their child nodes.
int isSumProperty(Node *root)
{
 // Add your code here
    int sum=0;
    if(root==NULL)
    {
    return 1;
    }
    if(root->left==NULL && root->right== NULL)
    {
        return 1;
    }
    if(root->left!=NULL)
    {
    sum+=root->left->data;
    }
    if(root->right!=NULL)
    {
    sum+=root->right->data;
    }
    if(sum==root->data&&isSumProperty(root->left)&&isSumProperty(root->right))
    {
    return 1;
    }
return 0;
}
