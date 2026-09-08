class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return mid;

            // mid is in the left part
            if (nums[mid] > nums[n - 1]) {

                if (nums[mid] < target) {
                    // target is to the right of mid
                    lo = mid + 1;
                }
                else {
                    // target may be in left part
                    if (nums[0] <=target) {
                        hi = mid - 1;
                    }
                    else {
                        lo = mid + 1;
                    }
                }
            }

            // mid is in the right part
            else {

                if (nums[mid] > target) {
                    hi = mid - 1;
                }
                else {
                    // target may be to the right
                    if (target <=nums[n - 1]) {
                        lo = mid + 1;
                    }
                    else {
                        hi = mid - 1;
                    }
                }
            }
        }

        return -1;
    }
};