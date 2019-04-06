class Solution {
private:
    int min(int a, int b) {
        return a < b ? a : b;
    }
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<int> row_max(m, 0);
        vector<int> col_max(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                row_max[i] = (grid[i][j] > row_max[i]) ? grid[i][j] : row_max[i];
                col_max[j] = (grid[i][j] > col_max[j]) ? grid[i][j] : col_max[j];
            }
        }
        int sum = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                sum += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return sum;
    }
};