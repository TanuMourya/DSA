class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    result[i]=max(result[i],result[j]+1);
                }
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,result[i]);
        }
        return ans;
    }
};