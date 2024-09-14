//Question Link : https://leetcode.com/problems/distinct-subsequences/

// Memoization 
class Solution {
public:
    int solve(int i, int j,  string &s, string &t , vector<vector<int>>&dp){
        if(j>=t.length()){
            return 1;
        }
        if(i>=s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans2 = 0;
        if(s[i]==t[j]){
            ans2 = solve(i+1 , j+1 , s,t ,dp);
        }
        int ans1 = solve(i+1 , j, s, t, dp);
        return dp[i][j] = ans2 + ans1;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0 ,0, s , t ,dp);
    }
};

//Tabulation 
class Solution {
public:
    int solve(string& s , string &t){
        int n = s.length();
        int m = t.length();
        vector<vector<unsigned long long>> dp(n +1 , vector<unsigned long long>(m+1, 0));
        for(int i =0 ; i <=n;i++){
            dp[i][m] = 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                unsigned long long ans1 =0 ;
                if(s[i]==t[j]){
                    ans1 = dp[i+1][j+1];
                }
                unsigned long long ans2 = dp[i+1][j];
                dp[i][j]=  ans1+ ans2;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        return solve(s , t);
    }
};
