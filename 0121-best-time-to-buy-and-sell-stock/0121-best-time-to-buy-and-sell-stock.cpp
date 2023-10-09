class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), result = 0;
        if (n == 0) return 0;
        vector<int> dp(n+100);
        dp[0] = prices[0];
        for(int i = 1 ; i<n; i++){
            result = max(result, prices[i]-dp[i-1]);
            dp[i] = min(dp[i-1], prices[i]);
        }
        return result;
    }
};