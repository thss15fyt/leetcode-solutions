class Solution {
public:
    int getSize(vector<vector<int>>& grid, int row, int col) {
        int size = 1;
        grid[row][col] = 0;
        if(row > 0 && grid[row - 1][col])
            size += getSize(grid, row - 1, col);
        if(row < grid.size() - 1 && grid[row + 1][col])
            size += getSize(grid, row + 1, col);
        if(col > 0 && grid[row][col - 1])
            size += getSize(grid, row, col - 1);
        if(col < grid[row].size() - 1 && grid[row][col + 1])
            size += getSize(grid, row, col + 1);
        return size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j]) {
                    int size = getSize(grid, i, j);
                    if(size > max_size)
                        max_size = size;
                }
            }
        }
        return max_size;
    }
};