// Question Link : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

//Memoizaiton 
class Solution {
  public:
    int ans = 0;
    int solve(int i , int j , string &str1 , string &str2 , vector<vector<int>>&dp){
        if(i>=str1.length()){
            return 0;
        }
        if(j>=str2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        solve(i, j+1 , str1 , str2 ,dp);
        solve(i+1 , j , str1 , str2 ,dp);
        int ans1=0;
        if(str1[i]==str2[j]){
            ans1 = 1 +  solve(i+1 , j+1 , str1 , str2 ,dp);
            dp[i][j]= ans1;
            ans = max(ans , dp[i][j]);
            return dp[i][j];
        }
        return dp[i][j] = 0;
    }
    int longestCommonSubstr(string str1, string str2) {
        vector<vector<int>> dp(str1.length() , vector<int>(str2.length() , -1));
        solve(0 ,0 , str1 , str2, dp);
        return  ans;
    }
};

//tabulation 
class Solution {
  public:
    int solveTab(string &str1 , string &str2){
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(str1.length()+1 , vector<int>(str2.length()+1 , -1));
        for(int i =0 ; i<=m;i++){
            dp[n][i] = 0;
        }
        for(int i = 0 ; i <=n;i++){
            dp[i][m]= 0 ;
        }
        int ans =0 ;
        for(int i = n-1;i >=0;i--){
            for(int j = m-1;j>=0;j--){
                if(str1[i]==str2[j]){
                dp[i][j] = 1+ dp[i+1][j+1];
                ans = max(ans , dp[i][j]);
                }else{
                    dp[i][j] =0 ;   
                }
            }
        }
        return ans;
    }
    int longestCommonSubstr(string str1, string str2) {
        return solveTab(str1 , str2);
    }
};
