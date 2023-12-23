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

//Tabulation
class Solution {
public:
    int solveTab(vector<int>&nums){
        vector<vector<int>> dp(nums.size() +1 , vector<int>(nums.size()+1 , 0));
        for(int i =nums.size()-1; i>=0;i--){
            for(int j =i-1 ; j>=-1;j--){
                int include =0 ; 
                if(j==-1 || nums[i]>nums[j]){
                    include = 1+dp[i+1][i+1];
                }
                int exclude= dp[i+1][j+1];
                 dp[i][j+1]= max(include , exclude);
                    }
                }
                return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        return solveTab(nums);
    }
};


//DP with binary search 
class Solution {
public:
    int solveOptimal(vector<int>&nums){
        if(nums.size()==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 0; i <nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin() , ans.end() , nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        return solveOptimal(nums);
    }
};

