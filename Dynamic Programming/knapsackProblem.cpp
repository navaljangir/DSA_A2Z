//DP Memoisation
class Solution
{
    public:
     int solve(int index , int wt[] , int val[] , int capacity ,vector<vector<int>>&dp){
        if(index==0){
            if(wt[0] <=capacity){
                return val[0];
            }else{
                return 0; 
            }
        } 
        if(dp[index][capacity]!=-1){
            return dp[index][capacity];
        }
        int include = 0 ;
         int exclude = 0; 
         if(wt[index]<=capacity){
             include = val[index] + solve(index-1 , wt , val , capacity- wt[index] , dp);
         }
         exclude = solve(index-1, wt,  val , capacity , dp);
         return dp[index][capacity]  =  max(include , exclude);
     }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n , vector<int>(W+1, -1));
       return solve(n-1 , wt, val , W , dp);
      
    }
};


//---------------------------- DP Tabulation ------------------------------------------//


class Solution
{
    public:
    int knapsackMaxSum(int capacity, int wt[] , int val[] , int n ){
        vector<vector<int>> dp(n , vector<int>(capacity+1, 0));
        for(int i = wt[0]; i<=capacity; i++){
            dp[0][i] = val[0];
        }
        for(int i =1 ; i <n; i++){
            for(int j = 0 ; j <=capacity;j++){
                int include =0;
                if(wt[i] <=j){
                    include = val[i] + dp[i-1][j-wt[i]];
                }
               int exclude = dp[i-1][j];
                dp[i][j] = max(include ,exclude);
            }
        }
        return dp[n-1][capacity];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n , vector<int>(W+1, -1));
       return knapsackMaxSum(W , wt, val ,n);
      
    }
};


//------------------------- Space optimisation -------------------------------------------//
class Solution
{
    public:
    int knapsackMaxSum(int capacity, int wt[] , int val[] , int n ){
        vector<vector<int>> dp(n , vector<int>(capacity+1, 0));
        for(int i = wt[0]; i<=capacity; i++){
            dp[0][i] = val[0];
        }
        for(int i =1 ; i <n; i++){
            for(int j = 0 ; j <=capacity;j++){
                int include =0;
                if(wt[i] <=j){
                    include = val[i] + dp[i-1][j-wt[i]];
                }
               int exclude = dp[i-1][j];
                dp[i][j] = max(include ,exclude);
            }
        }
        return dp[n-1][capacity];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n , vector<int>(W+1, -1));
       return knapsackMaxSum(W , wt, val ,n);
      
    }
};
