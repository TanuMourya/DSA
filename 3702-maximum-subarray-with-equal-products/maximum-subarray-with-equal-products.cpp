
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for(int j = i; j < n; j++) {
                long long x = nums[j];

                g = gcd(g, x);
                l = l / gcd(l, x) * x;

                // Avoid overflow
                if (prod > 1e15 / x)
                    break;

                prod *= x;

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
