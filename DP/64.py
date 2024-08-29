from typing import List
import numpy as np

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # dp = [[0] * len(grid) for _ in len(grid[0])]
        row = len(grid)
        col = len(grid[0])
        dp = np.zeros((row,col))
        dp[0][0] = grid[0][0]
        for i in range (1,row):
            dp[i][0] = dp[i-1][0] + grid[i][0]
        for j in range (1,col):
            dp[0][j] = dp[0][j-1] + grid[0][j]
        for i in range(1,row):
            for j in range(1,col):
                dp[i][j] = min(dp[i-1,j],dp[i,j-1]) + grid[i][j]
                
        return int(dp[row-1][col-1])
            
