"""
https://leetcode.cn/problems/unique-paths/description/?envType=study-plan-v2&envId=dynamic-programming
"""

import numpy as np
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = np.zeros((m, n))
        dp[0, :] = 1
        dp[:, 0] = 1
        for i in range(1,m):
            for j in range(1,n):
                dp[i,j] = dp[i-1][j] + dp[i][j-1]
                
        return int(dp[m-1,n-1])
    