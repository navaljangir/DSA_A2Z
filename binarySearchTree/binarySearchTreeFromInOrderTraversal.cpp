#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data= data;
        this->right = NULL;
        this->right=NULL;
    }
};
Node* solve(vector<int>& inOrder, int s ,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    int element = inOrder[mid];
    Node* root= new Node(element);
    root->left = solve(inOrder, s, mid-1);
    root->right = solve(inOrder,  mid+1 , e);
    return root;
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout<<q.front()->data<<" ";
        if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }
        q.pop();
    }
}
int main(){
vector<int> inOrder= {1,2,3,4,5,6,7,8,9};
int s = 0;
int e = inOrder.size()-1;
cout<<e;       
cout<<" mai gadha hu ";
Node* root  = solve(inOrder  ,s , e);
levelOrderTraversal(root);
}
