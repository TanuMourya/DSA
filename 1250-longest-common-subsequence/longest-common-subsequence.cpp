class Solution {
public:
    int fun(string &a,string &b,int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i==m || j==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=1+fun(a,b,m,n,i+1,j+1,dp);
        }
        int c1=fun(a,b,m,n,i+1,j,dp);
        int c2=fun(a,b,m,n,i,j+1,dp);
        return dp[i][j]=max(c1,c2);
    }
    int longestCommonSubsequence(string a, string b) {
        int m=a.length();
        int n=b.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fun(a,b,m,n,0,0,dp);
    }
};