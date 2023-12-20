//Dp bottom up 
class Solution {
public: 
    bool solve(vector<int>&nums , int index , int sum , int&target ,vector<vector<int>>&dp){
        if(sum==target){
            return true;
        }
        if(sum>target){
            return false;
        }
        if(index>=nums.size()){
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool include = solve(nums, index+1 , sum+nums[index] , target, dp);
        bool exclude = solve(nums, index+1 , sum , target, dp);

        return dp[index][sum] =  include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
       for(int i =0 ; i <nums.size();i++){
           totalSum+=nums[i];
       } 
       if(totalSum%2!=0){
           return false;
       }
       totalSum = totalSum/2;
        vector<vector<int>> dp(nums.size()+1 , vector<int>(totalSum+1, - 1));
        return solve(nums, 0 , 0 , totalSum ,dp);

    }
};

//Tabulation Method
class Solution {
public:
bool canBeEqualSubset(vector<int>& nums, int&target){
    vector<vector<int>> dp(nums.size()+1 , vector<int>(target+1, 0));
    for(int i =0 ; i <nums.size();i++){
        dp[i][0] = 1;
    }
    int n= nums.size();
    for(int i = n-1; i>=0;i--){
        for(int t= 1; t<=target;t++){
            bool include =false;
            if(t-nums[i]>=0){
                include = dp[i+1][t-nums[i]];
            }
            bool exclude = dp[i+1][t];
            dp[i][t] = include || exclude ;
        }
    }
    return dp[0][target];
}
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
       for(int i =0 ; i <nums.size();i++){
           totalSum+=nums[i];
       } 
       if(totalSum%2!=0){
           return false;
       }
       totalSum = totalSum/2;
        return canBeEqualSubset(nums, totalSum);
    }
};

//Space optimisation 
class Solution {
public:
bool canBeEqualSubsetSO(vector<int>& nums, int&target){
   vector<int> next(target+1);
   vector<int> curr(target+1);
    next[0] = 1;
    curr[0] =1;
    for(int i = nums.size()-1;i>=0;i--){
        for(int t = 1; t<=target;t++){
            bool include = false;
            if(t-nums[i]>=0){
                include = next[t-nums[i]];
            }
            bool exclude = next[t];
            curr[t] = include || exclude ;
        }
        next= curr;
    }
    return next[target];
}
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
       for(int i =0 ; i <nums.size();i++){
           totalSum+=nums[i];
       } 
       if(totalSum%2!=0){
           return false;
       }
       totalSum = totalSum/2;
        return canBeEqualSubsetSO(nums, totalSum);
    }
};


//More space optitmised - O(target+1)
class Solution {
public:
bool canBeEqualSubsetSO(vector<int>& nums, int&target){
   vector<int> curr(target+1);
    curr[0] =1;
    for(int i = 0;i<nums.size();i++){
        for(int t = target; t>=1;t--){
            bool include = false;
            if(t-nums[i]>=0){
                include = curr[t-nums[i]];
            }
            bool exclude = curr[t];
            curr[t] = include || exclude ;
        }
    }
    return curr[target];
}
    bool canPartition(vector<int>& nums) {
        int totalSum =0;
       for(int i =0 ; i <nums.size();i++){
           totalSum+=nums[i];
       } 
       if(totalSum%2!=0){
           return false;
       }
       totalSum = totalSum/2;
        return canBeEqualSubsetSO(nums, totalSum);
    }
};
