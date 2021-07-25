/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
        void verSum(Node *root, int hp, map<int, int> &mp)
{
    if(root)
    {
        mp[hp] += root->data;
        
        verSum(root->left,  hp - 1, mp);
        verSum(root->right, hp + 1, mp);
    }
}

    vector <int> verticalSum(Node *root) {
        
       vector<int> res;
    
    map<int, int> mp;
    int hp = 0;
    
    verSum(root, hp, mp);
    
    for(auto x: mp)
    {
        int val = x.second;
        
        res.push_back(val);
    }
    
    return res;
    }
};
