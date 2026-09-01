class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n+1,0);
        for(int i=0;i<n;i++){
            f[nums[i]]++;
            if(f[nums[i]]>1)return nums[i];
        }
        return 0;
    }
};