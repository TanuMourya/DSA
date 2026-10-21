class Solution {
public: 
    void reverse_arr(vector<int>& nums,int i,int j){
        while(i<j){
           swap(nums[i],nums[j]);
           i++;
           j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n)return;
        k=k%n;
        reverse_arr(nums,0,n-k-1);
        reverse_arr(nums,n-k,n-1);
        reverse_arr(nums,0,n-1);
        return;
    }
};