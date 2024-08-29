"""
343. 整数拆分
https://leetcode.cn/problems/integer-break/description/
"""
class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0] * (n+1)
        # dp[1] = 0 -> 0*1=0
        for i in range(2,n+1):
            for j in range(i):
                dp[i] = max(dp[i],j*(i-j),j*dp[i-j])
        return dp[n]