// Question Link : https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1

class Solution {
  public:
    vector<int> solve(vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n);
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[i] = max(dp[i] , dp[j]+1);
                }
            }
        }
        int maxiSize = 0;
        for(int i =0 ; i<n;i++){
            maxiSize = max(dp[i] , maxiSize);
        }
        int i =0 ; 
        vector<int> ans;
        while(i<n){
            if(dp[i]==maxiSize){
                ans.push_back(nums[i]);
                maxiSize--;
            }
            i++;
        }
        return ans;
    }
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        return solve(arr);
    }
};
