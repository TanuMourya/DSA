
class Solution {
public:
    void fun(vector<int>& nums, vector<int> temp,
             vector<vector<int>>& ans, vector<int>& used) {

        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 0) {
                temp.push_back(nums[i]);
                used[i] = 1;

                fun(nums, temp, ans, used);

                temp.pop_back();
                used[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(), 0);

        fun(nums, temp, ans, used);

        return ans;
    }
};
