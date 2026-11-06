class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {

        int m = nums.size();
        int n = nums[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // Check first row
        for(int j = 0; j < n; j++) {
            if(nums[0][j] == 0)
                firstRow = true;
        }

        // Check first column
        for(int i = 0; i < m; i++) {
            if(nums[i][0] == 0)
                firstCol = true;
        }

        // Mark rows and columns
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                if(nums[i][j] == 0) {
                    nums[i][0] = 0;
                    nums[0][j] = 0;
                }
            }
        }

        // Set marked rows to zero
        for(int i = 1; i < m; i++) {
            if(nums[i][0] == 0) {
                for(int j = 1; j < n; j++)
                    nums[i][j] = 0;
            }
        }

        // Set marked columns to zero
        for(int j = 1; j < n; j++) {
            if(nums[0][j] == 0) {
                for(int i = 1; i < m; i++)
                    nums[i][j] = 0;
            }
        }

        // Handle first row
        if(firstRow) {
            for(int j = 0; j < n; j++)
                nums[0][j] = 0;
        }

        // Handle first column
        if(firstCol) {
            for(int i = 0; i < m; i++)
                nums[i][0] = 0;
        }
    }
};