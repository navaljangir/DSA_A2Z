class Solution{
public:
  
    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*> q;
        q.push(root0);
        q.push(NULL);
        int index = 1;
        while(!q.empty() && index<vec.size()){
            node* top = q.front();
            q.pop();
            if(top!=NULL){
                top->left = newNode(vec[index++]);
                q.push(top->left);
                if(index<vec.size()){
                    top->right = newNode(vec[index++]);
                    q.push(top->right);
                }
            }else{
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
    
    }

};
