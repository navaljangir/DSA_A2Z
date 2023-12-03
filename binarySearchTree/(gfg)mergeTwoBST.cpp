class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       stack<Node*> s1;
       stack<Node*> s2;
       Node* a= root1;
       Node* b = root2;
       while(a!=NULL || b!=NULL || !s1.empty() || !s2.empty()){
           while(a!=NULL){
               s1.push(a);
               a=a->left;
           }
           while(b!=NULL){
               s2.push(b);
               b=b->left;
           }
           if(s2.empty() || (!s1.empty() && s1.top()->data<=s2.top()->data)){
               auto s1top = s1.top();
               s1.pop();
               ans.push_back(s1top->data);
               a=s1top->right;
           }else{
                   auto s2top = s2.top();
                   s2.pop();
                   ans.push_back(s2top->data);
                   b = s2top->right;
           }
       }
       return ans;
    }
};
