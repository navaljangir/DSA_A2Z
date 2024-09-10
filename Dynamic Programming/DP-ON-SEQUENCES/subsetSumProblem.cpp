//Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//memoization
class Solution{   
public:
    bool solve(vector<int>&arr , int i , int n ,int sum , vector<vector<int>>&dp){
        if(sum<0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(i>=n){
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        bool ans = solve(arr, i+1 , n , sum-arr[i] ,dp);
        ans= ans ||  solve(arr, i +1 , n, sum, dp);
        return dp[i][sum] =ans;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));
        return solve(arr, 0 , n , sum, dp);
    }
};

//Tabulation
class Solution{   
public:
    bool solveTab(vector<int>&arr , int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n+1 , vector<bool>(sum+1,0));
        for(int i =0 ;i <= n ; i++){
            dp[i][0] = 1;
        }
        for(int i = n-1; i>=0;i--){
            for(int j = sum;j>=0;j--){
                bool ans = false;
                if(j>=arr[i]){
                    ans = dp[i+1][j-arr[i]];
                }
                ans = ans || dp[i+1][j];
                dp[i][j] = ans;
            }
        }
        return dp[0][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return solveTab(arr, sum);
    }
};
//space optimized 
class Solution{   
public:
    bool solveOpti(vector<int>&arr , int sum){
        int n = arr.size();
        vector<bool> next(sum+1, false);
        next[0] = 1;
        vector<bool> curr(sum+1 , 0);
        curr[0]=  1;
        for(int i = n-1; i>=0;i--){
            for(int j = sum;j>=0;j--){
                bool ans = false;
                if(j>=arr[i]){
                    ans = next[j-arr[i]];
                }
                ans = ans || next[j];
                curr[j] = ans;
            }
            next=  curr;
        }
        return next[sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        return solveOpti(arr, sum);
    }
};
