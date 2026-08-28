class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26);

        for(char c : s)
            freq[c - 'a']++;

        int odd = 0;
        int mid = -1;

        for(int i = 0; i < 26; i++) {
            if(freq[i] & 1) {
                odd++;
                mid = i;
            }
        }

        if(odd > 1)
            return "";

        for(int i = 0; i < 26; i++)
            freq[i] /= 2;

        string ans(n, 'a');
        int half = n / 2;

        auto makePalindrome = [&]() {
            if(mid != -1)
                ans[half] = 'a' + mid;

            for(int i = 0; i < half; i++)
                ans[n - 1 - i] = ans[i];
        };

        int pos = 0;

        while(pos < half) {
            int c = target[pos] - 'a';

            if(freq[c] == 0)
                break;

            ans[pos] = target[pos];
            freq[c]--;
            pos++;
        }

        if(pos == half) {
            makePalindrome();

            if(ans > target)
                return ans;
        }

        while(true) {
            if(pos < half) {
                int c = target[pos] - 'a' + 1;

                while(c < 26 && freq[c] == 0)
                    c++;

                if(c < 26) {
                    ans[pos] = 'a' + c;
                    freq[c]--;

                    int idx = pos + 1;

                    for(int x = 0; x < 26; x++) {
                        while(freq[x]--) {
                            ans[idx++] = 'a' + x;
                        }
                    }

                    makePalindrome();
                    return ans;
                }
            }

            if(pos == 0)
                return "";

            pos--;
            freq[target[pos] - 'a']++;
        }
    }
};