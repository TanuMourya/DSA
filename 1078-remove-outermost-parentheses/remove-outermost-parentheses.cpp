 class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) ans += c;  // not outer
                st.push('(');
            } else {
                st.pop();
                if (!st.empty()) ans += c;  // not outer
            }
        }
        return ans;
    }
};

