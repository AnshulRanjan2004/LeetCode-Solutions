class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        
        if(numRows == 0) return dp;
        
        dp[0]={1};
        if (numRows == 1) return dp;
        
        for(int i=1;i<numRows;i++){
            dp[i].resize(i + 1);
            dp[i][0] = 1;
            dp[i][i] = 1;
            
            for (int j=1;j<i;j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        
        return dp;
    }
};