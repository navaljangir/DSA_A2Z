//Question Link : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
//Memoization 
class Solution {
public:
    int solve(int i , int j , vector<int>&cuts , int stickStart , int stickEnd , vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 1e9;
        for(int k=i  ; k <=j;k++){
                int leftAns =solve( i , k-1 , cuts , stickStart , cuts[k], dp );
                int rightAns =  solve( k+1 , j  , cuts , cuts[k] ,stickEnd, dp);
                ans= min(ans , stickEnd-stickStart + leftAns + rightAns);
        }
        return dp[i][j] =  ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        vector<vector<int>> dp(cuts.size()+1 , vector<int>(cuts.size()+1 ,- 1));
        return solve( 0 ,cuts.size()-1 , cuts ,  0, n , dp);
    }
};

//Memoization 2

class Solution {
public:
    int solve(int i , int j , vector<int>&cuts , vector<vector<int>>&dp){
        if(j-i<=1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 1e9;
        for(int k=i+1  ; k <j;k++){
                int leftAns =solve( i , k , cuts , dp );
                int rightAns =  solve( k , j  , cuts ,  dp);
                ans= min(ans , cuts[j]-cuts[i] + leftAns + rightAns);
        }
        return dp[i][j] =  ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end());
        vector<vector<int>> dp(cuts.size()+1 , vector<int>(cuts.size()+1 ,- 1));
        return solve( 0 ,cuts.size()-1 , cuts , dp);
    }
};


// Tabulation 

