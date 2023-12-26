//DP top down
class Solution {
public:
    int solve(int i , int j , string s , string t ,vector<vector<int>>&dp){
        if(j>=t.length()){
            return 1;
        }
        if(i>=s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int include =0 ; 
        if(s[i]==t[j]){
        include = solve(i+1 , j+1 , s, t ,dp);
        }
        int exclude = solve(i+1 , j, s, t, dp);
        return dp[i][j] = include + exclude;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1 , vector<int>(t.length()+1 , -1));
        return solve(0 , 0 , s, t ,dp);
    }
};


//Tabulation Method
class Solution {
public:
    int mod = 1e9+7;
    int distinctSubsequences(string s, string t){
        vector<vector<long long>> dp(s.length()+1, vector<long long>(t.length()+1 , 0));
        for(int i =0 ; i<dp.size(); i++){
            dp[i][t.length()] = 1;
        }
        for(int i = s.length()-1; i>=0;i--){
            for(int j = t.length()-1;j>=0;j--){
                long long include =0 ; 
                if(s[i]==t[j]){
                include = dp[i+1][j+1];
                }
                long long exclude = dp[i+1][j];
                dp[i][j] = (include + exclude)%mod;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        return distinctSubsequences(s,t);
    }
};
