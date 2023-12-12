class TrieNode{
    public:
        TrieNode* children[58];
        char data;
        bool isTerminal;
        TrieNode(char d){
            this->data =d; 
            this->isTerminal = false;
            for(int i =0 ; i<58;i++){
                this->children[i] = NULL;
            }
        }
};
class Solution {
public:
    void insert(string s , TrieNode* root ){
        if(s.length()==0){
            root->isTerminal =true;
            return;
        }
        int index = s[0]-'A';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(s[0]);
            root->children[index]=child;
        }
        insert(s.substr(1) , child);
    }
    bool search(string &s, int i , TrieNode* root){
        if(i>=s.length()){
            return root->isTerminal;
        }
        int index = s[i]-'A';
        if(root->children[index]){
            return search(s , i+1, root->children[index]);
        }else if(islower(s[i])){
            return search(s, i+1, root);
        }
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        TrieNode* root = new TrieNode('-');
        insert(pattern , root);
        vector<bool> ans;
        for(int i =0 ; i<queries.size();i++){
            int j =0;
            ans.push_back(search(queries[i] , j , root));
        }
        return ans;
    }
};
