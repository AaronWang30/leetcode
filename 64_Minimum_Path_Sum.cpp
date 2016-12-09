class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto size = grid.size();
        if(size==0) return 0;
        auto height = grid[0].size();
        for(int i = 1; i < size+height-1; ++i) {
            if(i < height)
                grid[0][i] = grid[0][i-1] + grid[0][i];
            if(i < size)
                grid[i][0] = grid[i-1][0] + grid[i][0];
            for(int j = 1; j < i ; ++j) {
                if(j < size && i - j < height)
                    grid[j][i-j] = min(grid[j-1][i-j], grid[j][i-j-1]) + grid[j][i-j];
            }
        }
        return grid[size-1][height-1];
    }
};