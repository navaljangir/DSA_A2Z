class NodeData{
public:  //yha glti hogi u might not use public
    int minVal;
    int maxVal;
    int size ;
    bool validBST;
    NodeData(){

    }
    NodeData(int size ,int min , int max , bool valid){
        this->size = size;
        this->minVal=min;
        this->maxVal=max;
        this->validBST=valid;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeData solve(Node* root , int &ans){
    if(root==NULL){
        NodeData temp(0 , INT_MAX , INT_MIN , true);
        return temp;
    }
    NodeData leftKaAns = solve(root->left , ans);
    NodeData rightKaAns = solve(root->right , ans);
    NodeData currNodeKaAns;
    currNodeKaAns.size = leftKaAns.size + rightKaAns.size+1;
    currNodeKaAns.maxVal = max(root->data , rightKaAns.maxVal);
    currNodeKaAns.minVal = min(root->data , leftKaAns.minVal);
    if(leftKaAns.validBST && rightKaAns.validBST && root->data > leftKaAns.maxVal && root->data < rightKaAns.minVal){
        currNodeKaAns.validBST=true;
    }else{
        currNodeKaAns.validBST=false;
    }
    if(currNodeKaAns.validBST){
        ans = max(ans , currNodeKaAns.size);
    }
    return currNodeKaAns;
}
    int largestBst(Node *root)
    {
     int ans = 0;
     NodeData temp= solve(root , ans);
     return ans;
    	
    }
};
