class Solution {
public:
vector<string> ans;
    void solve(int i , string&digits ,string s , unordered_map<char,string>&mp){
    if(i>=digits.size()){
        ans.push_back(s);
        return;
    }
    for(auto j : mp[digits[i]]){
        s+=j;
        solve(i+1 , digits ,s ,mp);
        s.pop_back();
    }
    return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(0 , digits , "" , mp);
    return ans;
    }
};
