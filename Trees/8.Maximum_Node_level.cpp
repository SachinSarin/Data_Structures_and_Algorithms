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

// Return the level (0-indexed) with maximum number of nodes.
int maxNodeLevel(Node *root)
{
    queue<Node*> q;
    q.push(root);
    int count = 0;
    int level = -1;
    int result = INT_MIN;
    while(q.empty()==false)
    {
        
        count = q.size();
      
        
        for(int i = 0; i < count; i++ )
        {
                Node* curr = q.front();
                q.pop();
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
         
        }
               if(count > result)
            {
            result = count;
            level++;
            }
        
    }
    return level;
}
