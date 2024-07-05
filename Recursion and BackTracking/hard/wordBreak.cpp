//problem link : https://leetcode.com/problems/word-break/
class Solution {
public:
    bool solve(int index , string s , unordered_map<string,int>&mp , vector<int>&dp){
        if(index>=s.length()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string str = "";
        bool ans = false;
        for(int i = index ; i < s.length();i++){
            str+=s[i];
            if(mp.find(str)!=mp.end()){
                ans = ans || solve(i+1 , s , mp, dp);
                if(ans==true){
                    break;
                }
            }
        }
        return dp[index]= ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto i : wordDict){
            mp[i]= 1;
        }
        vector<int> dp(s.length()+1 , -1 );
        return solve(0 , s , mp ,dp);
    }
};
