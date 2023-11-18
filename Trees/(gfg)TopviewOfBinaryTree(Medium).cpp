class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> mp;
        queue<pair<Node* ,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            if(mp.find(q.front().second)==mp.end()){
                mp[q.front().second] = q.front().first->data;
            }
            pair<Node* ,int> p = q.front();
            if(p.first->left!=NULL){
                q.push({p.first->left ,p.second-1});
            }
            if(p.first->right!=NULL){
                q.push({q.front().first->right , q.front().second+1});
            }
            q.pop();
        }
        vector<int> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }

};
