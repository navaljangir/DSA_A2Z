class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            this->data =val;
            this->left=NULL;
            this->right=NULL;
        }
        // Node(int val):data(val) , left(0) , right(0) {};
};

class Solution{
    public:
    Node* solve(Node*root , int val , int&succ){
        if(root==NULL){
            return new Node(val);
        }
        if(root->data>val){
            succ=root->data;
            root->left = solve(root->left , val ,succ);
        }else{
            root->right = solve(root->right , val ,succ);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root = NULL;
        vector<int> ans(arr.size(),-1);
        for(int i = arr.size()-1 ;i>=0;i--){
            int succ = -1;
            root = solve(root , arr[i] , succ);
            ans[i]= succ;
        }
        return ans;
    }
};
