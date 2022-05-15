class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = (int) s.size();
        map<char, char> mp = {
            {')', '('}, {'}', '{'}, {']', '['},
        };
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (st.empty() || st.top() != mp[s[i]]) return false;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};