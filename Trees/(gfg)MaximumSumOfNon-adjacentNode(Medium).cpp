// TLE Solution recursion
class Solution{
  public:
    int solve(Node* root , bool taken){
        if(root==NULL){
            return 0;
        }
        int take = 0;
        // int notTaken =0 ;
        if(taken==false){
            take = root->data + solve(root->left, true);
            take = take + solve(root->right ,true);
        }
        int notTaken = solve(root->left , false);
        notTaken=notTaken + solve(root->right , false);
        return max(take , notTaken);
        // return sum;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
       return solve(root, false);
        // return maxi;
    }
};

