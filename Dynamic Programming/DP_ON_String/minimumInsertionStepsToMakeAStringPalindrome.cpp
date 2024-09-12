// Question Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

//Memoization 
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

// Tabulation 
  
