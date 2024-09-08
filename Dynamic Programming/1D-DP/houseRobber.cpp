//memoization
class Solution {
public:
    int solve(vector<int>&nums , int index , vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans1 = nums[index] + solve(nums , index+2, dp);
        int ans2=  solve(nums , index+1, dp);
        return dp[index] = max(ans1 , ans2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return solve(nums , 0 , dp);
    }
};

//tabulation
class Solution {
public:
    int solve(vector<int>&nums , int index , vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int ans1 = nums[index] + solve(nums , index+2, dp);
        int ans2=  solve(nums , index+1, dp);
        return dp[index] = max(ans1 , ans2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return solve(nums , 0 , dp);
    }
};

//soace optimized
class Solution {
public:
    int spaceOpti(vector<int>&nums){
        int next1 = 0 ;
        int next2 =0 ;
        int n = nums.size();
        for(int i = n-1 ; i >=0; i--){
            int curr=  -1;
            curr = max({curr , nums[i] + next2 , next1});
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        return spaceOpti(nums);
    }
};
