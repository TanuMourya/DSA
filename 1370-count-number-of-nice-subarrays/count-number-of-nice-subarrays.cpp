class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int n_odds = 0;
        int ans = 0;
        int even = 0;

        for(int j = 0; j < n; j++) {
            if(nums[j] % 2 != 0)
                n_odds++;

            while(n_odds > k) {
                if(nums[i] % 2 != 0)
                    n_odds--;
                i++;
                even = 0;
            }

            if(n_odds == k) {
                while(i < j && nums[i] % 2 == 0) {
                    even++;
                    i++;
                }
                ans += even + 1;
            }
        }

        return ans;
    }
};