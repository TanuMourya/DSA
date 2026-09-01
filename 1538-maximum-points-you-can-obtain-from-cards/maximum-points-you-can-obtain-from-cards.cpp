class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int len = n - k;

        int total = 0;
        for(int x : nums)
            total += x;

        int sum = 0;
        for(int i = 0; i < len; i++)
            sum += nums[i];

        int mn = sum;

        for(int j = len; j < n; j++) {
            sum += nums[j];
            sum -= nums[j - len];

            mn = min(mn, sum);
        }

        return total - mn;
    }
};