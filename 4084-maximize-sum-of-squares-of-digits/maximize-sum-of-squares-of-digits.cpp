class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)return "";
        string ans="";
        int k=sum/9;
        int rem=sum%9;
        ans+=string(k,'9');
        if(rem>0){
            ans+=to_string(rem);
        }
        while(ans.size()<num){
            ans+='0';
        }
        return ans;
    }
};