
class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int m = a.length();
        int n = b.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Build LCS table from bottom to top
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j],
                                   dp[i][j + 1]);
                }
            }
        }

        string ans = "";
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (a[i] == b[j]) {
                ans += a[i];
                i++;
                j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                ans += a[i];
                i++;
            } else {
                ans += b[j];
                j++;
            }
        }
        while (i < m) ans += a[i++];
        while (j < n) ans += b[j++];

        return ans;
    }
};
