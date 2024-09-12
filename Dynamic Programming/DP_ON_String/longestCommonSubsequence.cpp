//Leetcode : https://leetcode.com/problems/longest-common-subsequence/description/

//Memoization 
class Solution {
public:
    int solve(int i ,int j , string &text1 , string &text2,  vector<vector<int>>&dp){
        if(j>=text2.size()){
            return 0;
        }
        if(i>=text1.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 =0 ;
        if(text1[i]==text2[j]){
            ans1 = 1+ solve(i +1 , j+1 , text1 , text2 ,dp);
        }
        int ans2 = solve(i+1 , j , text1 , text2, dp);
        int ans3 = solve(i , j+1 , text1 , text2 , dp);
        return dp[i][j] = max({ans1 , ans2 ,ans3 });
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() +1 , vector<int>(text2.size()+1 , -1));
        return solve(0 ,0 , text1 , text2 , dp);
    }
};

// Tabulation 
class Solution {
public:
    int solveTab(string &s1 , string &s2){
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1e9));
        for(int i =0 ; i<=m;i++){
            dp[n][i] = 0;
        }
        for(int i =0 ; i<=n;i++){
            dp[i][m] = 0;
        }
        for(int i = n -1; i>=0;i--){
            for(int j =m -1;j>=0;j--){
                dp[i][j] = max({ dp[i+1][j] , dp[i][j+1]});
                if(s1[i]==s2[j]){
                    dp[i][j] = max(dp[i][j] , 1+ dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTab(text1 , text2);
    }
};
