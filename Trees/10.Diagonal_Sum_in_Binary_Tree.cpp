/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/
void dsum(Node* root , int start , map<int,int> &mp)
{
    if(root==NULL)
    {
        return;
    }
    mp[start]+=root->data;
    dsum(root->left,start+1,mp);
    dsum(root->right,start,mp);
}
vector <int> diagonalSum(Node* root) {
    // Add your code here
    vector<int> result;
    if(root==NULL)
    {
        return result;
    }
    
    map<int,int> mp;
    dsum(root,0,mp);
    for(auto x: mp)
    {
        result.push_back(x.second);
    }
    return result;
}
