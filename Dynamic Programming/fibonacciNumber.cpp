//top down 
class Solution {
public:
    int topDown(vector<int>&dp , int n ){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = topDown(dp , n-1) + topDown(dp , n-2);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1 , -1);
        return topDown(dp ,n);   
    }
};

//bottom up 
class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        dp[0] =0;
        if(n>=1){
            dp[1]=1;
        }
        for(int i =2; i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//space optimisation
class Solution {
public:
    int fib(int n) {
        int prev2 = 0 ;
        int prev1 = 1;
        if(n==0)
            return prev2;
        if(n==1){
            return prev1;
        }
        int curr;
        for(int i =2; i<=n;i++){
            curr = prev1+prev2;
            prev2= prev1;
            prev1 = curr;
        }
        return curr;
    }
};
