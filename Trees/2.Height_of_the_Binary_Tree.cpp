//FIND THE HEIGHT OF THE BINARY Tree
class Solution{
    public:
    //Function to find the height of a binary tree.

    int height(struct Node* root){
        // code here 
        if(root==NULL)
        {
            return 0;
        }
        return 1 + max(height(root->left),height(root->right));
        
    }
};
