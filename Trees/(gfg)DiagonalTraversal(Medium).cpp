void solve(Node*root , int i, map<int,vector<int>>&mp){
    if(root==NULL){
        return;
    }
    mp[i].push_back(root->data);
    solve(root->left , i+1, mp);
    solve(root->right , i , mp);
}
vector<int> diagonal(Node *root)
{
   map<int,vector<int>> mp;
   solve(root , 0 , mp);
//   num+=1;
   vector<int> ans;
    for(auto i : mp){
        for(auto j:i.second){
            ans.push_back(j);
        }
    }
//   return ans;
return ans;
}

//iterative
vector<int> diagonal(Node *root)
{
   // your code 
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp!=NULL){
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            temp = temp->right;
        }
        
    }
    return ans;
}
