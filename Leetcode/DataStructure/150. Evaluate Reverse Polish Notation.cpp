class Solution {
public:
    bool isNumber (string & s) {
        if ((int) s.size() == 1 && (s[0] == '-' || s[0] == '+' || s[0] == '*' || s[0] == '/')) return false;
        return true;
    }
    int convert (string & s) {
        int res = 0;
        int l = 0;
        if (s[l] == '-' || s[l] == '+') ++l;
        for (int i = l; i < (int) s.size(); ++i) {
            res = res * 10 + (s[i] - '0');
        }
        if (s[0] == '-') res *= -1;
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for (string s : tokens) {
            if (isNumber(s)) {
                st.push_back(convert(s));
            } else {
                int x = st.back();
                st.pop_back();
                int y = st.back();
                st.pop_back();
                if (s == "+") {
                    st.push_back(y + x);
                } else if (s == "-") {
                    st.push_back(y - x);
                } else if (s == "*") {
                    st.push_back(y * x);
                } else {
                    if (x == 0) {
                        st.push_back(0);
                    } else {
                        st.push_back(y / x);
                    }
                }
            }
        }
        return st.back();
    }
};