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

    map<int,vector<pair<int,int>>> mp;
    void solve(int i , int j  , TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[j].push_back({i , root->val});
        solve(i+1 , j-1, root->left);
        solve(i+1 , j+1, root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(0 ,0 , root);
        vector<vector<int>> v;
        for(auto &i : mp){
            sort(i.second.begin() , i.second.end());
            vector<int> arr;
            for(int j = 0; j < i.second.size();j++){
                arr.push_back(i.second[j].second);
            }
                v.push_back(arr);
        }
        return v;
    }
};
