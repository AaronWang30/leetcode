class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt(0);
        if(grid.size()==0||grid[0].size()==0) return 0;
        int row(grid.size());
        int col(grid[0].size());
        for(int i=0;i<row;++i) {
            for(int j=0;j<col;++j) {
                if(grid[i][j]==1) {
                    //up
                    if(i==0||grid[i-1][j]==0) ++cnt;
                    //down
                    if(i==row-1||grid[i+1][j]==0) ++cnt;
                    //left
                    if(j==0||grid[i][j-1]==0) ++cnt;
                    //right
                    if(j==col-1||grid[i][j+1]==0) ++cnt;
                }
            }
        }
        return cnt;
    }
};