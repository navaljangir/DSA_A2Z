// Dynamic programming

class Solution {
public:
    int solve(int index,  vector<int>&nums , int prev, vector<vector<int>>&dp){
        if(index>=nums.size()){
            return 0 ;
        }
        int include =0 ;     
        if(dp[index][prev+1]!=-1e9){
            return dp[index][prev+1];
        }
        if(prev==-1 || nums[index]>nums[prev]){
            include = 1+ solve(index+1 , nums , index ,dp);
        }
        int exclude= solve(index+1, nums, prev, dp);
        return dp[index][prev+1]= max(include , exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , -1e9));
        return solve(0, nums, -1 ,dp);
    }
};
