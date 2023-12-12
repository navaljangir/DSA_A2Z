class TrieNode{
    public:
    TrieNode* children[26];
    int freq;
    bool isTerminal;
    char data;
    TrieNode(char d){
        this->data = d;
        this->isTerminal = false;
        for(int i =0 ; i <26;i++){
            children[i]= NULL;
        }
        this->freq=0;
    }
};
class comp{
    public:  bool operator()(const pair<int,string> a ,const pair<int,string> b){
        if(a.first==b.first){
            return a<b;
        }else{
            return a.first>b.first;
        }
        
    }
};
class Solution {
public:
  
    void insert(TrieNode* root , string s){
        if(s.length()==0){
            root->isTerminal = true;
            root->freq++;
            return;
        }
        int index = s[0]-'a';
        TrieNode* child;
        if(root->children[index]){
            child = root->children[index];
        }else{
            child = new TrieNode(s[0]);
            root->children[index]= child;

        }
        insert(child , s.substr(1));
    }

    void traverse(TrieNode* root , priority_queue<pair<int,string>, vector<pair<int,string>> , comp> &pq, string&s , int&k){
        if(root->isTerminal){
        if(pq.size()<k){
            pq.push({root->freq , s});
        }else if(pq.size()==k){
            if(pq.top().first<root->freq){
                pq.pop();
                pq.push({root->freq , s});
            }
        }
        }
        for(int i = 0 ; i<26;i++){
            if(root->children[i]){
                char ch = i+'a';
                s+=ch;
                traverse(root->children[i] , pq, s, k);
                s.pop_back();
            }
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        TrieNode* root = new TrieNode('-');
        for(auto i : words){
            insert(root, i);
        }
        priority_queue<pair<int,string> , vector<pair<int,string>> , comp> pq;
        string s= "";
        traverse(root , pq, s ,k );
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
