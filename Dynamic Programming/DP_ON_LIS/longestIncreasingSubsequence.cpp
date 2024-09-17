//Question Link : https://leetcode.com/problems/longest-increasing-subsequence/description/

// Memoization 
class Solution {
public:
    int solve(vector<int>&nums , int index , int prev , vector<vector<int>>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int ans1 =0;
        if(prev==-1 || nums[index]>nums[prev]){
            ans1 = 1+ solve(nums , index+1 , index ,dp);
        }
        int ans2 =solve(nums, index+1 , prev ,dp);
        return dp[index][prev+1] = max(ans1 ,ans2);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size()+1, -1));
        return solve(nums ,0 ,-1 ,dp);
    }
};

//Tabulation 
class Solution {
public:
    int solveTab(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+2, 0));
        for(int i =0;i>=n+1;i++){
            dp[n][i]=0 ;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int ans1 =0 ;
                if(j==-1 || nums[i]>nums[j]){
                    ans1= 1 + dp[i+1][i+1];
                }
                int ans2 = dp[i+1][j+1];
                dp[i][j+1]= max(ans1 , ans2);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        return solveTab(nums);
    }
};

// Binary Search 
class Solution {
public:
    int solve(vector<int>&nums){
        vector<int> ans;
        for(int i =0 ; i < nums.size();i++){
            if((int)ans.size()==0){
                ans.push_back(nums[i]);
            }else{
                if(ans.back() < nums[i]){
                    ans.push_back(nums[i]);
                }else{
                    int index =  lower_bound(ans.begin() , ans.end() , nums[i]) - ans.begin();
                    ans[index] = nums[i];
                }
            }
        }
        return (int)ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums);
    }
}; 
