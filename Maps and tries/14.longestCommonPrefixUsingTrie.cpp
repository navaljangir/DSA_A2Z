class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char data){
        for(int i =0 ; i<26;i++){
            children[i]=NULL;
        }
        this->data = data;
        childCount = 0;
        this->isTerminal = false;
    }
};

class Solution {
public:
    void insertInTrie(string s , TrieNode* root){
        if(s.length()==0){
            root->isTerminal = true;
            return;
        }
        char ch = s[0];
        int index = ch- 'a';
        TrieNode* child; 
        if(root->children[index]!=NULL){
            child = root->children[index];
        }else{
            child = new TrieNode(ch);
            root->childCount++;
            root->children[index] = child;
        }
        insertInTrie(s.substr(1), child);
    }
    void solve(string& ans , string s , TrieNode* root){
        if(root->isTerminal==true){
            return;
        }
           for(int i =0 ; i <s.length(); i++){
               char ch = s[i];
               int index = ch-'a';
               if(root->childCount==1){
                   root= root->children[index];
                   ans.push_back(ch);

               }else{
                   break;
               }
               if(root->isTerminal==true){
                   break;
               }
           }
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        for(int i =0 ; i <strs.size();i++){
            insertInTrie(strs[i] , root);
        }
        string ans = "";
        solve(ans , strs[0] , root);
        return ans;
    }
};
