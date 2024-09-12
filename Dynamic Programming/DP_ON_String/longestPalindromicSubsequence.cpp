// Question Link: https://leetcode.com/problems/longest-palindromic-subsequence/

//Memoization 
class Solution {
public:
    int solve(int i , int j , string &s , string &s2 , vector<vector<int>>&dp){
        if(i>=s.length()){
            return 0;
        }
        if(j>=s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0 ;
        if(s[i]==s2[j]){
            ans = 1 + solve(i+1 , j+1 , s ,s2 , dp);
        }
        int ans2 = solve(i+1 , j , s ,s2 , dp);
        int ans3 = solve(i, j+1 , s ,s2 , dp);
        return dp[i][j] = max({ans , ans2 , ans3});
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        vector<vector<int>> dp(s.length() , vector<int>(s.length() , -1));
        return solve(0 ,0, s , s2 , dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(string s , string&s2){
        int n = s.length();
        vector<vector<int>> dp(n+1 , vector<int>(n+1, -1e9));
        for(int i =0 ; i <=n;i++){
            dp[i][n] = 0;
            dp[n][i] = 0;
        }
        for(int i = n-1 ;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(s[i]==s2[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                }
                    dp[i][j] = max({dp[i][j] , dp[i+1][j] , dp[i][j+1]});
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return solveTab(s , s2);
    }
};
