
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Return True if the given Binary Tree is a Full Binary Tree. Else return False
bool isFullTree (struct Node* root)
{
//add code here.
    if(root==NULL)
    {
        return false;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return true;
    }
    
    if(root->left&&root->right)
    {
        return isFullTree(root->left) && isFullTree(root->right);
    }
    return false;
}
