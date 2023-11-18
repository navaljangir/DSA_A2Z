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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> v;
        while(!q.empty()){
            if(q.front()==NULL){
                ans.push_back(v);
                q.pop();
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            v.push_back(q.front()->val);
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
        for(int i =0 ; i <ans.size();i++){
            if(i%2!=0)
            reverse(ans[i].begin() , ans[i].end());
        }
        return ans;
    }
};



