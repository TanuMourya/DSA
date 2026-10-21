class Solution {
public:
    int fun(vector<int>& nums,int i,int n,int amount,vector<vector<int>>& dp){
        if(amount==0)return 1;
        if(i==n)return 0;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int n_take=fun(nums,i+1,n,amount,dp);
        int take=0;
        if(amount>=nums[i]){
           take=fun(nums,i,n,amount-nums[i],dp);
        }
        return dp[i][amount]=n_take+take;
    }
    int change(int amount, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return fun(nums,0,n,amount,dp);
    }
};