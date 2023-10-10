class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[n + 1];
        dp[0] = {""};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (const string& x : dp[j]) {
                    for (const string& y : dp[i - j - 1]) {
                        dp[i].push_back("(" + x + ")" + y);
                    }
                }
            }
        }
        return dp[n];
    }
};