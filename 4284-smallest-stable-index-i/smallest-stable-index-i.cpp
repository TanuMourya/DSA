class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> v(n);
        v[0] = nums[0];

        for(int i = 1; i < n; i++) {
            v[i] = max(nums[i], v[i-1]);
        }

        for(int i = n-2; i >= 0; i--) {
            nums[i] = min(nums[i], nums[i+1]);
        }

        for(int i = 0; i < n; i++) {
            if(v[i] - nums[i] <= k)
                return i;
        }

        return -1;
    }
};