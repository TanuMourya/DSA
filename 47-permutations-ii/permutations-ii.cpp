class Solution {
public:
    void fun(vector<int>&nums,vector<int> temp,vector<vector<int>> & ans,vector<int>& used){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==1)continue;
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==0)continue;
            temp.push_back(nums[i]);
            used[i]=1;
            fun(nums,temp,ans,used);
            temp.pop_back();
            used[i]=0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>used(n,0);
        vector<vector<int>>ans;
        vector<int>temp;
        fun(nums,temp,ans,used);
        return ans;
    }
};