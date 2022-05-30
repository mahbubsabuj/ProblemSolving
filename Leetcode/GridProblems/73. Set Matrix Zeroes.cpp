class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        int m = (int) matrix[0].size();
        bool hasZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[0][i] == 0) {
                hasZero = true;
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    for (int k = 0; k < m; ++k) {
                        if (matrix[i][k] == 0) matrix[0][k] = 0;
                        matrix[i][k] = 0;
                    }
                    break;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < n; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m && hasZero; ++i) matrix[0][i] = 0;
    }
};