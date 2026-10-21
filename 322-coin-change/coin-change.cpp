
class Solution {
public:
    int fun(vector<int>& coins, int i, int n, int amount,
            vector<vector<int>>& dp) {

        if (amount == 0) return 0;
        if (i == n) return 1e9;

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int n_take = fun(coins, i + 1, n, amount, dp);

        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + fun(coins, i, n, amount - coins[i], dp);
        }

        return dp[i][amount] = min(n_take, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = fun(coins, 0, n, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};
