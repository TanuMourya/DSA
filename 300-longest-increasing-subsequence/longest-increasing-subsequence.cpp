class Solution {
public:
    int fun(vector<int>& nums,int n,int i,int prev,vector<vector<int>>& dp){
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1 || nums[i]>nums[prev]){
            int ntake=fun(nums,n,i+1,prev,dp);
            int take=1+fun(nums,n,i+1,i,dp);
            return dp[i][prev+1]=max(ntake,take);
        }
        return dp[i][prev+1]=fun(nums,n,i+1,prev,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
     return fun(nums,nums.size(),0,-1,dp);   
    }
};