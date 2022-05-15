class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (int i = 0; i < (int) strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (pair<string, vector<string>> p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};