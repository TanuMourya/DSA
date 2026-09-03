class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //MOORE'S algorithm
        int freq=0;
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(freq==0)ans=nums[i];
            if(ans==nums[i])freq++;
            else{
                freq--;
            }
        }
        return ans;
    }
};