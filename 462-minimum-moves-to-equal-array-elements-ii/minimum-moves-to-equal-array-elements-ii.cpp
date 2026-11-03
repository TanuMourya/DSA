class Solution {
public:
    long long value(vector<int>& nums,int v){
        long long a=0;
        for(int i=0;i<nums.size();i++){
            long long diff=abs(nums[i]-v);
            a=a+diff;
        }
        return a;
    }

    int minMoves2(vector<int>& nums) {
        long long ans=INT_MAX;
        int lo=*min_element(nums.begin(),nums.end());
        int hi=*max_element(nums.begin(),nums.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long cost1=value(nums,mid);
            long long cost2=value(nums,mid+1);
            ans=min(cost1,cost2);
            if(cost2>cost1){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return (int)ans;
    }
};