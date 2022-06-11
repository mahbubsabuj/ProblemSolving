class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        int n = (int) hand.size();
        for (int i = 0; i < n; ++i) {
            ++mp[hand[i]];
        }
        sort (hand.begin(), hand.end());
        for (int i = 0; i < n; ++i) {
            if (mp[hand[i]] == 0) continue;
            int x = hand[i];
            int cnt = 1;
            --mp[x];
            while (cnt < groupSize && mp[x + 1] > 0) {
                ++cnt;
                --mp[++x];
            }
            if (cnt != groupSize) return false;
        }
        return true;
    }
};