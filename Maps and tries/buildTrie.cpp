#include<iostream>
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
int main(){
     TrieNode* root = new TrieNode('-');
        insertWord(root , "string");
}
