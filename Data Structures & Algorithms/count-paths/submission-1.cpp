#include <cstring>
class Solution {
public:
    int memo[101][101];

    int paths(int row, int col, int m, int n)
    {
        if(row == m - 1 && col == n - 1) return 1;

        if(row >= m)
            return 0;

        if(col >= n)
            return 0;

        if(memo[row][col] != -1) return memo[row][col];

        int ways = paths(row + 1, col, m, n) + paths(row, col + 1, m, n);

        return memo[row][col] = ways;
    }
    int uniquePaths(int m, int n) {
       memset(memo, -1, sizeof(memo));
        
        int res = paths(0,0, m, n);
        return res;
    }
};