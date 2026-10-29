class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            int len=j-i+1;
            while( mp.size()<len){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                len=j-i+1;
            }
            ans=max(ans,len);
            j++;
        }
        return ans;
    }

};