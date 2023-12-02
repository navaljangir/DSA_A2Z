//Ysing MaxVal and MinVal and recursion //Only Auxilary Space for recursion 
class Solution{
  public:
   bool solve(Node* root ,int minVal ,int maxVal){
        if(root==NULL){
            return false;
        }
       if(root->left==NULL && root->right==NULL){
           if(root->data==1){
               return true;
           }
           if(root->data - minVal ==1 && maxVal-root->data==1){
               return true;
           }
       }
      bool leftKaAns= solve(root->left ,minVal , root->data);
    bool rightKaAns= solve(root->right,root->data , maxVal);
        return leftKaAns || rightKaAns;
    }
    bool isDeadEnd(Node *root)
    {
       return solve(root, INT_MIN, INT_MAX);
    }
};

//Using map and recursion O(n) Extra space
class Solution{
  public:
    void solve(Node* root , unordered_map<int,bool>& visited, bool&ans){
        if(root==NULL){
            return;
        }
        visited[root->data]=true;
        if(root->left==NULL && root->right==NULL){
            int num1 = root->data+1;
            int num2 = root->data-1;
            if(num2==0){
                num2 = root->data;
            }
            if(visited.find(num1)!=visited.end() && visited.find(num2)!=visited.end()){
                ans=true;
                return;
            }
            
        }
        solve(root->left , visited ,ans);
        solve(root->right,visited, ans);
        
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        bool ans =false;
        unordered_map<int,bool> visited;
        solve(root,visited,ans);
        return ans;
    }
};
