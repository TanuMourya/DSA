class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, INT_MAX);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int l = 0; l < n; l += k) {
                int r = l + k - 1;
                int descents = 0;

                // Count descents inside the block
                for (int j = l; j < r; j++) {
                    if (nums[j] > nums[j + 1]) {
                        descents++;
                    }
                }
                if (nums[r] > nums[l]) {
                    descents++;
                }

                if (descents > 1) {
                    ok = false;
                    break;
                }

                if (r + 1 < n &&
                    prefMax[r + 1] > suffMin[r + 1]) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};