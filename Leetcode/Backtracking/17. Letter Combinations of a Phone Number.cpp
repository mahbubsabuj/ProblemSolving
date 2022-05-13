class Solution {
public:
    vector<string> combinations = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void f (string &s, int i, string now) {
        if (i == (int) s.size()) {
            res.push_back(now);
            return;
        }
        for (char c : combinations[s[i] - '0' - 2]) {
            f(s, i + 1, now + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        if ((int) digits.size() == 0) return res;
        f(digits, 0, "");
        return res;
    }
};