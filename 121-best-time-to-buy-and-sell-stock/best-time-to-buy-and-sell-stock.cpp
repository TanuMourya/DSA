class Solution {
public:
    int fun(vector<int>& nums,int i,int n,int k,vector<vector<int>>& dp){
        if(i==n || k==0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        if(k==2){
            int c1=fun(nums,i+1,n,k-1,dp)-nums[i];
            int c2=fun(nums,i+1,n,k,dp);
            return dp[i][k]=max(c1,c2);
        }
        if(k==1){
            int c1=fun(nums,i+1,n,k-1,dp)+nums[i];
            int c2=fun(nums,i+1,n,k,dp);
            return dp[i][k]=max(c1,c2);
        }
        return 0;
    }
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return fun(nums,0,n,2,dp);
    }
};