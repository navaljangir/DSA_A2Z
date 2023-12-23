//DP - TLE
class Solution {
public:
    int solve(vector<vector<int>>& envelops , int index ,int prev ,vector<vector<int>>&dp){
        if(index>=envelops.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int include = 0;
        
        if(prev==-1 || (envelops[index][0] > envelops[prev][0] && envelops[index][1] >envelops[prev][1] )){
            include = 1 + solve(envelops , index+1 , index,dp);
        }
        int exclude = solve(envelops , index+1 , prev, dp);
        return dp[index][prev+1] = max(include , exclude);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<vector<int>> dp(envelopes.size()+1, vector<int>(envelopes.size()+1 , -1));
        sort(envelopes.begin() , envelopes.end());
        return solve(envelopes , 0 , -1 ,dp);
    }
};

//DP - Tab 
class Solution {
public:
    int solveTab(vector<vector<int>>& cuboids){
        vector<vector<int>> dp(cuboids.size()+1, vector<int>(cuboids.size()+1 , 0));
        for(int index = cuboids.size()-1; index>=0;index--){
            for(int prev = index-1; prev>=-1 ;prev--){
                int include = 0;
            if(prev==-1 || (cuboids[index][0]>=cuboids[prev][0] && cuboids[index][1]>=cuboids[prev][1] && cuboids[index][2]>=cuboids[prev][2])){
                include = cuboids[index][2] + dp[index+1][index+1];
            }
            int exclude = dp[index+1][prev+1];
                dp[index][prev+1]  =max(include, exclude);
                }
            }
            return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i =0 ; i <cuboids.size();i++){
            sort(cuboids[i].begin() , cuboids[i].end());
        }
        sort(cuboids.begin() , cuboids.end());
        return solveTab(cuboids);

    }
};

//DP - space optimised
class Solution {
public:
    int solveTab(vector<vector<int>>& cuboids){
        vector<int> next(cuboids.size()+1);
        vector<int> curr(cuboids.size()+1);
        for(int index = cuboids.size()-1; index>=0;index--){
            for(int prev = index-1; prev>=-1 ;prev--){
                int include = 0;
            if(prev==-1 || (cuboids[index][0]>=cuboids[prev][0] && cuboids[index][1]>=cuboids[prev][1] && cuboids[index][2]>=cuboids[prev][2])){
                include = cuboids[index][2] + next[index+1];
            }
            int exclude = next[prev+1];
                curr[prev+1]  =max(include, exclude);
                }
                next= curr;
            }
            return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i =0 ; i <cuboids.size();i++){
            sort(cuboids[i].begin() , cuboids[i].end());
        }
        sort(cuboids.begin() , cuboids.end());
        return solveTab(cuboids);

    }
};
