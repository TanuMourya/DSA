
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> molqaviren = grid;

        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][x] = can XOR value x reach cell (i,j)?
        vector<vector<vector<char>>> dp(
            m, vector<vector<char>>(
                n, vector<char>(1024, 0)
            )
        );

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int x = 0; x < 1024; x++) {
                    if (!dp[i][j][x]) continue;

                    // Move down
                    if (i + 1 < m) {
                        int nextXor = x ^ grid[i + 1][j];
                        dp[i + 1][j][nextXor] = 1;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int nextXor = x ^ grid[i][j + 1];
                        dp[i][j + 1][nextXor] = 1;
                    }
                }
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
