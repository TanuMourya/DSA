
class Solution {
public:
    vector<vector<long long>> dp;

    long long fun(vector<int>& nums, int i, int n, int sign) {
        if (i == n) return 0;

        if (dp[i][sign] != -1)
            return dp[i][sign];

        long long c1, c2;

        if (sign == 0) {
            // Add this element
            c1 = nums[i] + fun(nums, i + 1, n, 1);
            c2 = fun(nums, i + 1, n, 0);
        } else {
            // Subtract this element
            c1 = -1LL * nums[i] + fun(nums, i + 1, n, 0);
            c2 = fun(nums, i + 1, n, 1);
        }

        return dp[i][sign] = max(c1, c2);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));

        return fun(nums, 0, n, 0);
    }
};
