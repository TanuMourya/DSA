class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int a = -1;
        int b = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                a = i;
            }

            if(nums[i] > maxi) {
                maxi = nums[i];
                b = i;
            }
        }

        int left = min(a, b);
        int right = max(a, b);

        int x = right + 1;
        int y = n - left;
        int z = left + 1 + n - right;

        return min({x, y, z});
    }
};