class Solution
{
    public:
    int sum(Node* root ){
        if(root==NULL){
            return 0;
        }
        int ans = root->data + sum(root->left)+ sum(root->right);
        return ans;
    }
    bool isSumTree_helper(Node*root){
        if(root==NULL){
             return true;
         }
         if(root->left==NULL && root->right==NULL){
             return true;
         }
         bool ans = false;
         if(root->data==(sum(root->left)+sum(root->right))){
             ans= true;
         }
         bool leftAns = isSumTree_helper(root->left);
         bool rightAns = isSumTree_helper(root->right);
         return ans && leftAns && rightAns;
    }
    bool isSumTree(Node* root)
    {
        return isSumTree_helper(root);    
    }
};
