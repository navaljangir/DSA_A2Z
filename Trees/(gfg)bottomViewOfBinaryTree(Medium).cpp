class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node* ,int>> q;
        q.push({root , 0});
        vector<int> ans;
        map<int,int>mp;
        while(!q.empty()){
            mp[q.front().second]=q.front().first->data;
            if(q.front().first->left!=NULL){
                q.push({q.front().first->left,q.front().second-1});
            }
            if(q.front().first->right!=NULL){
                q.push({q.front().first->right , q.front().second+1});
            }
            q.pop();
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
