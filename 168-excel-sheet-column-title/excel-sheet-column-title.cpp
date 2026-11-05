class Solution {
public:
    string convertToTitle(int n) {
        string ans="";
        while(n>0){
            n--;
            int x=n%26;
            char ch='A'+x;
            ans+=ch;
            n=n/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};