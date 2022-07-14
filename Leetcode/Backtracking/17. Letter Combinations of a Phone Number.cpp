
class Solution {
public:
    vector<string> combinations = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string now = "";
    void f (string &s, int i) {
        if (i == (int) s.size()) {
            res.push_back(now);
            return;
        }
        for (char c : combinations[s[i] - '0' - 2]) {
            now.push_back(c);
            f(s, i + 1);
            now.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        if ((int) digits.size() == 0) return res;
        f(digits, 0);
        return res;
    }
};