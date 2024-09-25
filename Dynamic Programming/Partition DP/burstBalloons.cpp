// Question Link : https://leetcode.com/problems/burst-balloons/

//Memoization 
class Solution {
public:
    int solve(int i , int j , vector<int>&nums , vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k = i;k<=j;k++){
            int leftNum =1;
            int rightNum = 1;
            if(j+1<nums.size()){
                rightNum = nums[j+1];
            }
            if(i-1>=0){
                leftNum = nums[i-1];
            }
            ans = max(ans , leftNum * nums[k] * rightNum + solve(i , k-1, nums , dp) + solve(k+1 , j , nums, dp));
        }
        return dp[i][j] =  ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size(), -1));
        return solve(0 , nums.size()-1,nums, dp);
    }
};


// Tabulation 
  class Solution {
public:
    int solveTab(vector<int>& nums){
            int n = nums.size();
            vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1e9));
            for(int i = 0 ; i <=n;i++){
                for(int j = 0; j <=n;j++){
                    if(i>j){
                        dp[i][j] = 0;
                    }
                }
            }
            for(int i = n-1;i>=0;i--){
                int ans = INT_MIN;
                for(int j = 0 ; j <n ; j++){
                    for(int k = i; k<=j;k++){
                        int leftNum =1;
                        int rightNum = 1;
                            if(j+1<n){
                                rightNum = nums[j+1];
                            }
                            if(i-1>=0){
                                leftNum = nums[i-1];
                            }
                            int leftAns = 0;
                            if(k-1>=0){
                                leftAns = dp[i][k-1];
                            }
                            ans = max(ans , leftNum * nums[k] * rightNum + leftAns + dp[k+1][j]);
                        }
                        dp[i][j] = max(dp[i][j] , ans);
                }
            }
            return dp[0][n-1];
        }
    int maxCoins(vector<int>& nums) {
        int ans =  solveTab(nums);   
        return ans;
    }
};
