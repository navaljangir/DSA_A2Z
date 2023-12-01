//Inorder traversal using the stack
class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
    int ans=0 ;
    stack<Node*> s1;
    stack<Node*> s2;
    Node* temp1 = root1;
    Node* temp2 =  root2;
    while(true){
        while(temp1!=NULL){
            s1.push(temp1);
            temp1=  temp1->left;
        }
        while(temp2!=NULL){
            s2.push(temp2);
            temp2 =temp2->right;
        }
        if(s1.empty() || s2.empty()){
            break;
        }
        Node* s1Top = s1.top();
        Node* s2Top= s2.top();
        int sum = s1Top->data + s2Top->data;
        if(sum==x){
            ans++;
            s1.pop();
            s2.pop();
            temp1 = s1Top->right;
            temp2 = s2Top->left;
        }
        else if(sum<x){
            s1.pop();
            temp1 = s1Top->right;
        }else{
            s2.pop();
            temp2 = s2Top->left;
        }
    }
    return ans;
    }
};
