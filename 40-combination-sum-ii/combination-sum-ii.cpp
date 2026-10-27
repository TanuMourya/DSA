class Solution {
public:
    void fun(vector<int>& nums,int i,int n,vector<int> temp,vector<vector<int>>& ans,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==n || target<0){
            return;
        }
            temp.push_back(nums[i]);
            fun(nums,i+1,n,temp,ans,target-nums[i]);
            temp.pop_back();
        
        int j=i+1;
        while(j<n && nums[i]==nums[j]){
            j++;
        }
        fun(nums,j,n,temp,ans,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        fun(nums,0,n,temp,ans,target);
        return ans;
    }
};