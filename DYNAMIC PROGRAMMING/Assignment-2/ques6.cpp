// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(); //row size
        int n = grid[0].size(); //column size

        //first column fillup for min sum- only one way to move- from top
        for(int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        //first row fillup for min sum
        for(int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
        }

        //fill the remaining cells with their min sum- only one way to move- from left

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];

    }
};