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

//Iterative // Using Queue
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root , {0,0}});
        while(!q.empty()){
            auto &p = q.front();
            TreeNode*&temp = p.first;
            int&row = p.second.first;
            int&col = p.second.second;
            mp[col][row].insert(temp->val);
            if(temp->left){
                q.push({temp->left , {row+1 , col-1}});
            }
            if(temp->right){
                q.push({temp->right, {row+1 , col+1}});
            }
            q.pop();
        }
        vector<vector<int>> ans;
        for(auto col: mp){
            vector<int> v;
           for(auto&row : col.second){
               auto&mset = row.second;
               v.insert(v.end() , mset.begin() , mset.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};
