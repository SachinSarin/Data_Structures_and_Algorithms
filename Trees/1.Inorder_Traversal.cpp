/*
INORDER TRAVERSAL LEFT , ROOT , RIGHT
*/
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void applyinorder(Node* root , vector<int>&v)
    {
        if(root==NULL)
        {
            return;
        }
        applyinorder(root->left,v);
        v.push_back(root->data);
        applyinorder(root->right,v);
    }
    vector<int> inOrder(Node* root) {
        //apply inorder traversal left root right
        vector<int> result;
        applyinorder(root,result);
        return result;
        
    }
};
