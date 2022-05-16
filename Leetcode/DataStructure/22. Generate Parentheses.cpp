class Solution {
public:
    vector<string> res;
    vector<char> st;
    void f (int open, int close, int n) {
        if (open == n && close == n) {
            string p = "";
            for (char c : st) {
                p.push_back(c);
            }
            res.push_back(p);
            return;
        }
        if (open < n) {
            st.push_back('(');
            f(open + 1, close, n);
            st.pop_back();
        }
        if (close < open) {
            st.push_back(')');
            f(open, close + 1, n);
            st.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        f (0, 0, n);
        return res;
    }
};
