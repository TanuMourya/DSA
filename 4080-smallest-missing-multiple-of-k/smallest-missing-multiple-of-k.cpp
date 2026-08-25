class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        int i = 1;

        while(true) {
            int x = k * i;

            if(mp.find(x) == mp.end()) {
                return x;
            }

            i++;
        }
    }
};