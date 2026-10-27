
class Solution {
public:
    int check(vector<vector<int>>& nums, int i, int j,
              vector<vector<bool>>& visited, int count) {
        int m = nums.size();
        int n = nums[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n ||
            nums[i][j] == -1 || visited[i][j])
            return 0;

        if (nums[i][j] == 2) {
            return count == 1 ? 1 : 0;
        }

        visited[i][j] = true;

        int ans = 0;
        ans += check(nums, i + 1, j, visited, count - 1);
        ans += check(nums, i - 1, j, visited, count - 1);
        ans += check(nums, i, j + 1, visited, count - 1);
        ans += check(nums, i, j - 1, visited, count - 1);

        visited[i][j] = false; // backtracking

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size();
        int si = 0, sj = 0, count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i][j] != -1) count++;
                if (nums[i][j] == 1) {
                    si = i;
                    sj = j;
                }
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return check(nums, si, sj, visited, count);
    }
};
