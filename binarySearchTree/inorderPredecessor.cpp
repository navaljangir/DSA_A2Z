//Question Practice Link https://workat.tech/problem-solving/practice/inorder-predecessor-bst
//T.C = O(logn) 
//S.C = O(1)
Node* findPredecessor(Node* root, Node* p) {
    // add your logic here
	Node* pred = NULL;
	Node* curr = root;
	while(curr!=NULL){
		if(curr->data < p->data){
			pred = curr;
			curr = curr->right;
		}else{
			curr=curr->left;
		}
	}
	return pred;
}
