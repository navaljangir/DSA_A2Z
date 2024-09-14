//Question Link : https://leetcode.com/problems/wildcard-matching/description/

class Solution {
public:
    bool solve(string&s, int i , string&p ,int j , vector<vector<int>>&dp){
        if(i>=s.length() && j>=p.length()){
            return true;
        }
        if(i==s.length()){
            while(j<p.length()){
                if(p[j]!='*'){
                    return false;
                }
                j++;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans1 = false;
        if(s[i]==p[j] || p[j]=='?' || p[j]=='*'){
            ans1 = solve(s, i+1 , p , j+1 , dp);
        }
        bool ans2 = false;
        bool ans3 = false;
        if(p[j]=='*'){
            ans2 = solve(s , i+1 ,p , j ,dp);
            ans2 = ans2 || solve(s, i, p , j+1 , dp);
        }
        return dp[i][j] = ans1 || ans2;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1 , vector<int>(p.length()+1 ,-1));
        return solve(s,0, p, 0 , dp);
    }
};
