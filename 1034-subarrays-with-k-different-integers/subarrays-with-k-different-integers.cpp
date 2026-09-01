class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k == 0) return 0;

        unordered_map<int,int> mp;
        int i = 0;
        int ans = 0;

        for(int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};