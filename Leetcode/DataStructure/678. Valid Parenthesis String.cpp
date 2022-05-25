class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') open.push(i);
            else if (s[i] == '*') star.push(i);
            else {
                if (!open.empty()) open.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }
        if (open.empty()) return true;
        else {
            while (!open.empty()) {
                while(!star.empty()) {
                    if (star.top() < open.top()) star.pop();
                    else break;
                }
                if (star.empty()) return false;
                star.pop();
                open.pop();
            }
            return true;
        }
    }
};