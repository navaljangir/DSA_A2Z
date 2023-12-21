//DP
class Solution {
public:
    int solve(int i , int j , string&word1, string&word2, vector<vector<int>>&dp){
        if(j==word2.length()){
            return word1.length()-i;
        }
        if(i>=word1.length()){
            return word2.length()-j;
        }
        // if(i==)
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans= 0 ;
        if(word1[i]==word2[j]){
            ans = solve(i+1, j+1, word1, word2,dp);
        }else{
            int insertion = 1+ solve(i, j+1, word1, word2,dp);
            int deletion = 1 + solve(i+1, j , word1, word2,dp);
            int replace = 1+ solve(i+1, j+1, word1 , word2,dp);
            ans = min(insertion , min(deletion , replace));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1 , vector<int>(word2.length()+1, -1));
        return solve(0, 0, word1, word2,dp);
    }
};

//Tabulation Method

class Solution {
public:
    int solveUsingTab(string word1 , string word2){
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
      //dp me andr hr row ke andr last column pr yeh value daal do 
        for(int i = 0 ; i<word1.length() ; i++){
            dp[i][word2.length()] = word1.length()-i;
        }
        for(int j = 0 ; j<word2.length(); j++){
            dp[word1.length()][j] = word2.length()-j;
        }
        for(int i = word1.length()-1;i>=0;i--){
            for(int j = word2.length()-1;j>=0;j--){
                int ans= 0 ;
        if(word1[i]==word2[j]){
            ans =dp[i+1][j+1];
        }else{
            int insertion = 1+dp[i][j+1];
            int deletion = 1 + dp[i+1][j];
            int replace = 1+ dp[i+1][j+1];
            ans = min(insertion , min(deletion , replace));
        }
        dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return solveUsingTab(word1, word2);
    }
};

//space optimisation 
class Solution {
public:
    int solveUsingTabSO(string word1 , string word2){
        vector<int> next(word2.length()+1);
        vector<int> curr(word2.length()+1);
        for(int j = 0 ; j<word2.length(); j++){
            next[j] = word2.length()-j;
        }
        for(int i = word1.length()-1;i>=0;i--){
            //yha glti krenge ---> jb bhi ek nye row ki suruat hogi tb hi last index pr yeh value insert kr dunga
            curr[word2.length()] = word1.length()-i;
            for(int j = word2.length()-1;j>=0;j--){
                int ans= 0 ;
        if(word1[i]==word2[j]){
            ans =next[j+1];
        }else{
            int insertion = 1+curr[j+1];
            int deletion = 1 + next[j];
            int replace = 1+ next[j+1];
            ans = min(insertion , min(deletion , replace));
        }
        curr[j] = ans;
            }
            next= curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        return solveUsingTabSO(word1, word2);
    }
};
