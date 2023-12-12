class TrieNode{
    public:
    TrieNode* children[26];
    char data;
    bool isTerminal;
    TrieNode(char d){
        this->data= d;
        this->isTerminal = false;
        for(int i =0 ; i <26;i++){
            this->children[i] = NULL;
        }
    }
};

class Solution {
public:
    void insert(TrieNode* root , string s){
        if(s.length()==0){
            root->isTerminal = true;
            return;
        }
        char ch = s[0];
        int index= ch-'a';
        TrieNode* child;
        if(root->children[index]==NULL){
            child = new TrieNode(ch);
            root->children[index]= child;
        }else{
            child = root->children[index];
        }
        insert(child , s.substr(1));
    }
    bool findStr(TrieNode* root , string &s , int&k){
         if(root->isTerminal){
             return true;
         }
         if(k>=s.length()){
             return root->isTerminal;
         }
         int index = s[k++]-'a';
         if(root->children[index]){
             return findStr(root->children[index] , s , k);
         }
         return false;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode('-');
        string ans = "";
        for(auto i : dictionary){
            insert(root,  i);
        }   
        for(int i =0 ; i<sentence.size();i++){
            string s = "";
            int j = i;
            while(j<sentence.length() && sentence[j]!=' '){
                s+=sentence[j];
                j++; 
            }
            int k = 0;
            if(findStr(root , s, k)==true){
                ans+=s.substr(0,k);
            }else{
                ans+=s;
            }
            if(j!=sentence.length()){
                ans+=' ';
            }
            i=j;
        }
return ans;
    }
};
