#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left= NULL;
            right=NULL;
        }
};
Node* buildTree(){
    int data ; 
    // cout<<"Enter the root Node";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root = new Node(data);
    cout<<"Enter the leftNode of"<<data<<": ";
    root->left = buildTree();
    cout<<"Enter the rightNode of"<<data<<": ";
    root->right = buildTree();
    return root;
}
int main(){
    Node* root = buildTree();
}
