class Solution {
public:
    int fun(vector<int>& nums,int k,int n,int i,vector<vector<int>>& dp){
        if(i==n)return 0;
        if(k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        if(k==2){
            int c1=fun(nums,k-1,n,i+1,dp)-nums[i];
            int c2=fun(nums,k,n,i+1,dp);
            return dp[i][k]=max(c1,c2);
        }
        else{
            int c1=fun(nums,k-1,n,i+1,dp)+nums[i];
            int c2=fun(nums,k,n,i+1,dp);
            return dp[i][k]=max(c1,c2);
        }
    }
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return fun(nums,2,nums.size(),0,dp);
    }
};