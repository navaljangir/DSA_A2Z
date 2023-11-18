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
    map<int, vector<pair<int,int>>> mp;
    void solve(TreeNode* root , int i ,int j){
        if(root==NULL){
            return ;
        }
        mp[j].push_back({i , root->val});
        solve(root->left , i+1 , j -1);
        solve(root->right , i+1 , j+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root , 0 , 0);
        for(auto &i : mp){
            sort(i.second.begin() , i.second.end());
            vector<int> v;
            for(auto &values : i.second){
                v.push_back(values.second);
            }
        ans.push_back(v);
        }
        return ans;
    }
};
