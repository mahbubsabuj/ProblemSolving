class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = (int) s.size();
        vector<int> pos[26];
        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = 0;
        for (string word : words) {
            int m = (int) word.size();
            int prev_taken_pos = -1;
            bool yes = true;
            for (int i = 0; i < m; ++i) {
                //find min_pos of ith character from word string where min_pos > prev_taken_pos;
                int l = 0, r = (int) pos[word[i] - 'a'].size() - 1;
                int taken_pos = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (pos[word[i] - 'a'][mid] > prev_taken_pos) {
                        taken_pos = pos[word[i] - 'a'][mid];
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                if (taken_pos == -1) {
                    yes = false;
                    break;
                }
                prev_taken_pos = taken_pos;
            }
            res += yes;
        }
        return res;
    }
};