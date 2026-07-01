class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // Initialize with 1s

            for (int j = 1; j < i; j++) {
                row[j] = mat[i - 1][j - 1] + mat[i - 1][j];
            }

            mat.push_back(row);
        }

        return mat;
    }
};
