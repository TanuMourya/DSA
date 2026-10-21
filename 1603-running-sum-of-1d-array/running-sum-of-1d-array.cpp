class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        int a=nums[0];
        for(int i=1;i<n;i++){
            nums[i]=a+nums[i];
            a=nums[i];
        }
        return nums;
    }
};