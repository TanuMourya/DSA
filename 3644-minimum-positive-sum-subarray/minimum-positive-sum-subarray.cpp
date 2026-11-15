class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int len = l; len <= r; len++) {
            int i = 0, j = 0;
            int sum = 0;

            while(j < n) {
                sum += nums[j];

                if(j - i + 1 == len) {
                    if(sum > 0)
                        ans = min(ans, sum);

                    sum -= nums[i];
                    i++;
                }

                j++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};