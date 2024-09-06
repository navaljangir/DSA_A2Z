//memoization 
class Solution {
public:
    int recSum(int n){
        if(n == 1 || n == 2) return n;
        else return recSum(n-1) + recSum(n-2);
    }
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        int prev=1,cur=2,temp=0;
        for(int i=3;;i++){
            temp = cur;
            cur+=prev;
            prev = temp;
            if(i == n) return cur;
        }
        return 0;
    }
};

//tabulation 
class Solution {
public:
    int climbStairs(int n) {
         vector<int> dp(n+1, -1);
      dp[0]= 1;
      dp[1]= 1;
        for(int i =2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
//space optimised
class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 1;
        for(int i =2 ; i <= n ; i++){
            int curr = prev1 + prev2; 
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};
