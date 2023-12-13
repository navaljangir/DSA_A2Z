//Recursion 
class Solution {
public:
    int solvemem(vector<int>& nums , int i , int prev ){
        if(i>=nums.size()){
            return 0;
        }
        int take = 0 ;
        int notTake = 0; 
        if(prev==-1 || prev!=i-1){
            take = nums[i] + solvemem(nums , i+2,i); 
        }
        notTake = solvemem(nums , i+1 , prev);
        return  max(take , notTake);
    }
    int rob(vector<int>& nums) {
        return solvemem(nums , 0, -1 );
    }
};
/*-------------------------------------------------------------------------------------more optimised  ---------------------------------------------------------------------------------*/
    
//top down - 2d dp
class Solution {
public:
    int solvemem(vector<int>& nums , int i , int prev ,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take = 0 ;
        int notTake = 0; 
        if(prev==-1 || prev!=i-1){
            take = nums[i] + solvemem(nums , i+2 ,i,dp); 
        }
        notTake = solvemem(nums , i+1 , prev,dp);
        return dp[i][prev+1] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size(),-1));
        return solvemem(nums , 0, -1 ,dp);
    }
};


//1d dp
class Solution {
public:
    int solvemem(vector<int>& nums , int i  ,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take = 0 ;
        int notTake = 0;
        take = nums[i] + solvemem(nums , i+2 ,dp);
        notTake = solvemem(nums , i+1 , dp);
        return dp[i] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solvemem(nums , 0, dp);
    }
};


//Tabulation 
class Solution {
public:
    int solveTab(vector<int>&nums){
        vector<int> dp(nums.size()+1 , 0);
        int n = nums.size()-1;
        dp[n] = nums[n];
        for(int i = n-1; i>=0; i--){
            int inc = nums[i];
            if(i+2<=n)
                inc = inc+ dp[i+2];

            int exc = dp[i+1];
            dp[i] = max(inc , exc);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solveTab(nums );
    }
};
