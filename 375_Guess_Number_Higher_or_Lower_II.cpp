class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= n; ++i){
            for (int j = i - 1; j >= 1; --j){
                int min_value = INT_MAX;
                for (int k = j; k <= i; ++k){
                    min_value = min(min_value, k + max(dp[j][k - 1], dp[k + 1][i]));
                }
                dp[j][i] = min_value;
            }
        }
        return dp[1][n];
    }
};