//Question Link : https://leetcode.com/problems/edit-distance/description/

//Memoization 
class Solution {
public:
    int solve(int i, int j, string &word1 , string &word2 , vector<vector<int>>&dp){
        if(i>=word1.length()){
            return word2.length()-j;
        }
        if(j>=word2.length()){
            return word1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1= INT_MAX;
        if(word1[i]==word2[j]){
            ans1 = solve(i+1 , j +1, word1 , word2, dp); //same
        }
        int ans2 = 1+  solve(i+1 , j , word1 , word2, dp); //delete character
        int ans3 = 1+ solve(i+1 ,j +1,  word1 , word2, dp); // replace character
        int ans4 = 1+ solve(i, j+1, word1 ,word2, dp); // add character
        return dp[i][j] = min({ans1 , ans2 , ans3 ,ans4});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() , vector<int>(word2.length() , -1));
        return solve(0 ,0 , word1 , word2 , dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(string &word1 , string &word2){
        int n= word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 1e9));
        for(int i =0 ;i<=n;i++){
            dp[i][m] =n-i;
        }
        for(int i= 0 ;i <=m;i++){
            dp[n][i] = m-i;
        }
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int ans1= INT_MAX;
                if(word1[i]==word2[j]){
                    ans1 = dp[i+1][j+1];
                }
                int ans2 = 1+ dp[i+1][j];
                int ans3 = 1+ dp[i+1][j+1];
                int ans4 = 1+ dp[i][j+1];
                dp[i][j] = min({ans1 , ans2 , ans3 , ans4});
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return solveTab(word1 , word2);
    }
};
