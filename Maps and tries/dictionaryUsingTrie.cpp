#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char d){
        this->data = d; 
        for(int i=0 ; i <26;i++){
            children[i]= NULL;
        }
        this->isTerminal = false;
    }
};
void insertWord(TrieNode* root , string word){
if(word.length()==0){
    root->isTerminal = true;
    return;
}
TrieNode* child;
char ch = word[0];
int index = ch-'a';
if(root->children[index]!=NULL){
    child = root->children[index];
}else{
child = new TrieNode(ch);
root->children[index] = child;
}
insertWord(child , word.substr(1));

}
void findSuggesstions(TrieNode* root ,string& s,  vector<string>& v){
    if(root->isTerminal){
        v.push_back(s);
    }
    for(int i =0 ; i <26;i++){
        if(root->children[i]!=NULL){
            TrieNode* temp = root->children[i];
            s.push_back(i+'a');
            findSuggesstions(temp , s,v );
            s.pop_back();
        }
    }

}
vector<vector<string>> suggesstions(TrieNode* root , string s){
    string prefix = "";
    vector<vector<string>> ans;
    TrieNode* prev = root;
    for(int i =0 ; i <s.length(); i++){
        cout<<"chala:"<<i<<" ";
        char ch = s[i];
        int index= ch -'a';
        TrieNode* curr =prev->children[index];
        if(curr==NULL){
            cout<<"yha tut gya tha ";
            break;
        }else{
            vector<string> temp;
            prefix +=s[i];
            findSuggesstions(curr , prefix , temp);
            prev = curr;
            ans.push_back(temp);
        }

    }
    return ans;
}
int main(){
     TrieNode* root = new TrieNode('-');
        insertWord(root , "candy");
        insertWord(root , "candies");
        insertWord(root , "car");
        insertWord(root , "cant");
        insertWord(root , "contain");
        insertWord(root , "can");
        insertWord(root , "canteen");
        insertWord(root, "carry");
        vector<vector<string>> ans = suggesstions(root , "ca");
        for(int i =0 ; i <ans.size(); i++){
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

        
}
