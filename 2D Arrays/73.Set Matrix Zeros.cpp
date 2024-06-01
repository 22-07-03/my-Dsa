class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> rows, cols;

        // Step 1: Identify the rows and columns that need to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // Step 2: Set the identified rows to zero
        for (int row : rows) {
            for (int j = 0; j < m; j++) {
                matrix[row][j] = 0;
            }
        }

        // Step 3: Set the identified columns to zero
        for (int col : cols) {
            for (int i = 0; i < n; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
[73.Set Matrix Zeros.cpp](https://leetcode.com/problems/set-matrix-zeroes/submissions/1274443440/)
