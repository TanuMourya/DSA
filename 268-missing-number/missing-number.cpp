class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int &x:nums){
            total+=x;
        }
        int sum=(n*(n+1))/2;
        return sum-total;
    }
};