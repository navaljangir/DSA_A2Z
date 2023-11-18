class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        queue<pair<Node*,int>>q;
        map<int,vector<int>> mp;
        q.push({root , 0 });
        while(!q.empty()){
            pair<Node*,int> p = q.front();
            q.pop();
            mp[p.second].push_back(p.first->data);
            if(p.first->left!=NULL){
                q.push({p.first->left , p.second-1});
            }
            if(p.first->right!=NULL){
                q.push({p.first->right , p.second+1});
            }
        }
        for(auto i : mp){
            for(auto j : i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};
