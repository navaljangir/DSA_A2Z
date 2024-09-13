//Question Link : https://leetcode.com/problems/delete-operation-for-two-strings/description/

//Memoization 
class Solution {
public:
    int solve(int i , int j, string &word1 , string &word2 , vector<vector<int>>&dp){
        if(i>=word1.length() ){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1 = 1 + solve(i+1 , j , word1 , word2, dp);
        int ans2 = 1+ solve(i , j +1 , word1 , word2, dp);
        int ans3 = INT_MAX;
        if(word1[i]==word2[j]){
            ans3=  solve(i+1 ,j +1 , word1 , word2 ,dp);
        }
        return dp[i][j] = min({ans1, ans2 , ans3});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() , vector<int>(word2.length(), -1));
        return solve(0 ,0 , word1 , word2, dp);
    }
};

// Tabulation 
class Solution {
public:
    int solveTab(string &word1 , string &word2){
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n +1, vector<int>(m+1 , 1e9));
        for(int i = 0;i<=m;i++){
            dp[n][i] = m-i;
        }
        for(int i = 0 ; i <=n;i++){
            dp[i][m] = n-i;
        }
        for(int i = n -1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int ans1 = 1+ dp[i+1][j];
                int ans2 = 1+ dp[i][j+1];
                int ans3 = INT_MAX;
                if(word1[i]==word2[j]){
                    ans3=  dp[i+1][j+1];
                }
                dp[i][j] = min({ans1 , ans2, ans3});
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return solveTab(word1 , word2);
    }
};

//space tabulation 
class Solution {
public:
    int solveSpace(string &word1 , string &word2){
        int n = word1.length();
        int m = word2.length();
        vector<int> next(m+1 );
        vector<int> curr(m+1 );
        for(int i = 0;i<=m;i++){
            next[i] = m-i;
        }
        for(int i = n -1;i>=0;i--){
            curr[m] = n-i;
            for(int j = m-1;j>=0;j--){
                int ans1 = 1+ next[j];
                int ans2 = 1+ curr[j+1];
                int ans3 = INT_MAX;
                if(word1[i]==word2[j]){
                    ans3=  next[j+1];
                }
                curr[j] = min({ans1 , ans2, ans3});
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        return solveSpace(word1 , word2);
    }
};
