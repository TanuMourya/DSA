class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zero++;
            else if(nums[i]==1)one++;
        }
        int two=n-zero-one;
        for(int i=0;i<n;i++){
            if(i<zero)nums[i]=0;
            else if(i>=zero && i<one+zero)nums[i]=1;
            else{
                nums[i]=2;
            }
        }
        return ;
    }
};