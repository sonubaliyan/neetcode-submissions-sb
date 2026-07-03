class Solution {
public:

    int unq_path(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>> & dp)
    {
        if(row < 0 || col < 0 || obstacleGrid[row][col] == 1)
            return 0;
        if(row == 0 && col == 0 )
            return 1;

        if(dp[row][col] != -1) return dp[row][col];
        // there are two ways go up or go left
        dp[row][col] = unq_path(obstacleGrid, row-1, col, dp) + unq_path(obstacleGrid, row, col-1, dp);

        return dp[row][col];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        int res = unq_path(obstacleGrid, row-1, col-1, dp);

        return res;
        
    }
};