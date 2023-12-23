//DP - top down
class Solution {
public:
    int solve(vector<vector<int>>& cuboids , int index , int prev ,vector<vector<int>>&dp){
        if(index>=cuboids.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int include = 0;
        if(prev==-1 || (cuboids[index][0]>=cuboids[prev][0] && cuboids[index][1]>=cuboids[prev][1] && cuboids[index][2]>=cuboids[prev][2])){
            include = cuboids[index][2] + solve(cuboids , index+1 ,index,dp);
        }
        int exclude = solve(cuboids , index+1 ,prev,dp);
        return dp[index][prev+1 ]  =max(include, exclude);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(int i =0 ; i <cuboids.size();i++){
            sort(cuboids[i].begin() , cuboids[i].end());
        }
        vector<vector<int>> dp(cuboids.size()+1, vector<int>(cuboids.size()+1 , -1));
        sort(cuboids.begin() , cuboids.end());
        return solve(cuboids , 0, -1, dp);

    }
};
