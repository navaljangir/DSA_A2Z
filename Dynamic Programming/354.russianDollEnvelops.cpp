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


