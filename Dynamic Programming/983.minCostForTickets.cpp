class Solution {
public:
    int solve(int index , vector<int>& days , vector<int>&costs ,vector<int>&dp){
        if(index>=days.size()){
            return 0 ;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int oneDayCost = costs[0] + solve(index+1 , days , costs ,dp);
        int passValidity = days[index] + 7;
        int j = index;
        while(j<days.size() && passValidity>days[j]){
            j++;
        }
        int sevenDayCost = costs[1] + solve(j , days , costs ,dp);
        passValidity = days[index]+30;
        j = index;
        while(j<days.size() && passValidity>days[j]){
            j++;
        }
        int thirtyDaysCost = costs[2] + solve(j, days , costs ,dp);
        return dp[index]= min(oneDayCost , min(thirtyDaysCost , sevenDayCost));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         vector<int> dp(days.size()+1 , -1);
        return solve(0, days, costs ,dp);
    }
};
