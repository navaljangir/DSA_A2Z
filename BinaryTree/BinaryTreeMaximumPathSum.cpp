/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans =INT_MIN;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftAns =max(0 ,  solve(root->left));
        int rightAns =max(0 , solve(root->right));
        ans = max(ans , leftAns +rightAns+root->val);
        return max(leftAns ,rightAns) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
