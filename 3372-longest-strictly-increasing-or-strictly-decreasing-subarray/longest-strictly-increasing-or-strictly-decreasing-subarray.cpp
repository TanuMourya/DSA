
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        int i = 0, j = 0;

        // Increasing subarray
        while (j < n - 1) {
            if (nums[j] < nums[j + 1]) {
                j++;
                ans = max(ans, j - i + 1);
            }
            else {
                i = j + 1;
                j = i;
            }
        }

        // Decreasing subarray
        i = 0;
        j = 0;

        while (j < n - 1) {
            if (nums[j] > nums[j + 1]) {
                j++;
                ans = max(ans, j - i + 1);
            }
            else {
                i = j + 1;
                j = i;
            }
        }

        return ans;
    }
};
