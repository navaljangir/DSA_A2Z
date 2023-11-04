
class Solution {
  public:
    int solve(Node*root){
        if(root==NULL){
            return 0;
    }
    int currVal=root->data;
    
    root->data=solve(root->left)+solve(root->right);
    return root->data + currVal;
    }
    void toSumTree(Node *node)
    {
        solve(node);
        
    }
};
