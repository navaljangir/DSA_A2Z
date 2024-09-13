//QUestion link : https://leetcode.com/problems/shortest-common-supersequence/

//Tabulation 
class Solution {
public:
     string solveTab(string &str1, string &str2){
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1, -1e9));
        for(int i =0 ; i <=m;i++){
            dp[n][i] = 0;
        }
        for(int i = 0 ; i <=n;i++){
            dp[i][m] = 0;
        }
        for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(str1[i]==str2[j]){
                    dp[i][j] = 1+ dp[i+1][j+1];
                }
                    dp[i][j] =max(dp[i][j] ,  dp[i+1][j]);
                    dp[i][j] = max(dp[i][j] , dp[i][j+1]);
            }
        }
        int i =0 ;
        int j = 0 ;
        string ans = "";
        while(i<n && j<m){
            if(str1[i]==str2[j]){
                ans+=str1[i];
                i++;
                j++;
            }else if(dp[i][j+1]<=dp[i+1][j]){
                ans+=str1[i];
                i++;
            }else{
                ans+=str2[j];
                j++;
            }
        }
        while(i<n){
            ans+=str1[i++];
        }
        while(j<m){
            ans+=str2[j++];
        }

        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return solveTab(str1 , str2);
    }
};
