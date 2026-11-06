class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        set<int>r;
        set<int>c;
        int m=nums.size();
        int n=nums[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto i:r){
            for(int j=0;j<n;j++){
                nums[i][j]=0;
            }
        }
        for(auto i:c){
            for(int j=0;j<m;j++){
                nums[j][i]=0;
            }
        }
        return;
    }
};