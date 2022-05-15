class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string res = "";
        for (string s : strs) {
            if (res.size() > 0) res.push_back(',');
            res += s;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> res;
        string now = "";
        for (int i = 0; i < (int) str.size(); ++i) {
            if (str[i] == ',') {
                if ((int) now.size() > 0) {
                    res.push_back(now);
                    now = "";
                }
            } else {
                now.push_back(str[i]);
            }
        }
        if ((int) now.size() > 0) {
            res.push_back(now);
        }
        return res;
    }
};