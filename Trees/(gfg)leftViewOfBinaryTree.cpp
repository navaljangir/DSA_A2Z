//iterative
vector<int> leftView(Node *root)
{
   // Your code here
   if(root==NULL){
       return {};
   }
   vector<int> ans;
   ans.push_back(root->data);
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
       if(q.front()==NULL){
           q.pop();
           if(!q.empty()){
               ans.push_back(q.front()->data);
               q.push(NULL);
           }
           continue;
       }
       if(q.front()->left!=NULL){
           q.push(q.front()->left);
       }
       if(q.front()->right!=NULL){
           q.push(q.front()->right);
       }
       q.pop();
   }
   return ans;
}


//recursive


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
void leftView_helper(Node* root , int level , vector<int>&v){
    if(root==NULL){
        return;
    }
    if(v.size()==level){
        v.push_back(root->data);
    }
    leftView_helper(root->left , level + 1 , v);
    leftView_helper(root->right , level+1 , v) ;
}
vector<int> leftView(Node *root)
{
    vector<int> v; 
    leftView_helper(root , 0 , v);
    return v;
   // Your code here
}
