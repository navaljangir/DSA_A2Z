//problem link : https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<string> v;
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        int i = 0; 
        int j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int index , string s){
        if(index>=s.length()){
            ans.push_back(v);
            return; 
        }
        string str=  "";
        for(int i = index ; i < s.length();i++){
            str+=s[i];
            if(isPalindrome(str)){
            v.push_back(str);
            solve(i+1 , s);
            v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0, s);
        return ans;
    }
};
