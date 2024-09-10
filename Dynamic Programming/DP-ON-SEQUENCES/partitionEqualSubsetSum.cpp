//Memoization method: 1 
class Solution {
public:
    bool solve(vector<int>&nums , int i , int sum1 , vector<vector<int>>&dp){
        
        if(i>=nums.size()){
            if(sum1==0 ){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum1+20001]!=-1){
            return dp[i][sum1+20001];
        }
        bool ans1 = solve(nums , i+1 , sum1-nums[i], dp);
        bool ans2= solve(nums, i+1 , sum1+ nums[i], dp);
        return  dp[i][sum1+20001] = ans1 || ans2;
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(40002, -1));
        return solve(nums ,0  ,0 , dp);
    }
};

//Memoization method: 2
class Solution {
public:
    bool solve(vector<int>&nums , int i , int sum1 , vector<vector<int>>&dp){
        if(sum1<0){
            return false;
        }
        if(i>=nums.size()){
            if(sum1==0 ){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum1]!=-1){
            return dp[i][sum1];
        }
        bool ans1 = solve(nums , i+1 , sum1-nums[i], dp);
        bool ans2= solve(nums, i+1 , sum1 , dp);
        return  dp[i][sum1] = ans1 || ans2;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0 ;
        for(auto i: nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        sum= sum/2;
        vector<vector<int>> dp(nums.size() , vector<int>(sum+1 ,-1));
        return solve(nums ,0  ,sum, dp);
    }
};

//Tabulation 
class Solution {
public:
    bool solveTab(vector<int>&nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp(n+1 , vector<bool>(sum+1 , false));
        for(int i =0 ; i <=n;i++){
            dp[i][0] = 1;
        }
        for(int i = n-1;i>=0 ;i--){
            for(int j = sum;j>=0;j--){
                bool ans = false;
                if(j>=nums[i]){
                    ans= dp[i+1][j-nums[i]];
                }
                ans = ans || dp[i+1][j];
                dp[i][j]= ans;
            }
        }
        return dp[0][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0 ;
        for(auto i: nums){
            sum+=i;
        }
        if(sum%2!=0){
            return false;
        }
        sum= sum/2;
        return solveTab(nums  ,sum);
    }
};
