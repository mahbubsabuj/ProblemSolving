class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = (int) matrix[0].size() * (int) matrix.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / (int) matrix[0].size();
            int j = mid - i * (int) matrix[0].size();
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};