class Solution {
public:
    string decode(string &s, int &i) {
        string ans = "";

        while (i < s.length() && s[i] != ']') {

            // If we find a number
            if (isdigit(s[i])) {
                int num = 0;

                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                // Skip '['
                i++;

                // Decode what's inside []
                string temp = decode(s, i);

                // Skip ']'
                i++;

                // Repeat temp
                while (num--) {
                    ans += temp;
                }
            }

            // Normal character
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};