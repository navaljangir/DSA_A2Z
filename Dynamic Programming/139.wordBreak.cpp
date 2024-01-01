class Solution {
public:
    bool solve(int i ,string&s ,  unordered_map<string,bool>&mp , vector<int>&dp){
        if(i>=s.length()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string str= "";
        bool ans = false;
        for(int j = i;  j<s.length();j++){
            str+=s[j];
            if(mp[str]){
                ans = ans || solve(j+1 , s, mp , dp);
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> mp;
        for(auto i: wordDict){
            mp[i]=true;
        }
        vector<int> dp(s.length()+1 , -1);
    return solve(0 , s, mp ,dp);
    }
};
