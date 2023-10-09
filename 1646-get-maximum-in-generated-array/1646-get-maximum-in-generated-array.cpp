class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        vector<int> dp(n+10);
        dp[0] = 0;
        dp[1] = 1;
        int max_val = 1;
        for(int i = 2; i<=n;i++){
            if(i%2 == 0)dp[i] = dp[i/2];
            else dp[i] = dp[(i-1)/2] + dp[(i+1)/2];
            max_val = max(max_val, dp[i]);
        }
        return max_val;
    }
};