//memoization
class Solution {
public:
    int solve(vector<int>&nums , int i , int e , vector<int>&dp){
        if(i>=e){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans1 = nums[i] + solve(nums ,i+2 , e , dp);
        int ans2 = solve( nums , i+1, e , dp);
        return dp[i] = max(ans1 , ans2);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n+1, - 1);
        int ans1 = solve(nums , 0 , n- 1 , dp);
        dp.assign(dp.size() , -1);
        int ans2 = solve(nums , 1 , n , dp); 
        return max(ans1 , ans2);
    }
};
