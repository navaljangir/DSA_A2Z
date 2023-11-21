#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right =NULL;
    }
};
Node* createTree(Node*root , int data){
    if(root==NULL){
        root = new Node(data); 
        return root;
    }
    if(root->data>data){
        root->left = createTree(root->left , data);
    }
    if(root->data<data){
        root->right - createTree(root->right , data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root= createTree(root , data);
        cin>>data;
    }
}
int main(){
    
}
