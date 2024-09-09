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


//Tabulation 
class Solution {
public:
    int solveTab(vector<int>&nums , int s , int e){
        vector<int> dp(e-s+3, -1);
        dp[e] =0; 
        dp[e+1] = 0 ; 
        for(int i = e-1; i>=s; i--){
            dp[i] = max({dp[i] ,dp[i+1] , nums[i] + dp[i+2]});
        }
        return dp[s];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        int ans1 = solveTab(nums , 0 , n- 1 );
        int ans2 = solveTab(nums , 1 , n); 
        return max(ans1 , ans2);
    }
};

//Space optimized 
class Solution {
public:
    int solveTab(vector<int>&nums , int s , int e){
        int next1 =0 ;
        int next2 =0 ;
        for(int i = e-1; i>=s; i--){
            int curr = max({next1 , nums[i] + next2});
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        int ans1 = solveTab(nums , 0 , n- 1 );
        int ans2 = solveTab(nums , 1 , n); 
        return max(ans1 , ans2);
    }
};
