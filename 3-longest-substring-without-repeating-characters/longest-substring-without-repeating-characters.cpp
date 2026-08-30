class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        for (j = 0; j < n; j++) {
            mp[s[j]]++;

            int len = j - i + 1;

            while (len > mp.size()) {
                mp[s[i]]--;

                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }

                i++;
                len = j - i + 1;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};