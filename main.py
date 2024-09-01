def count_paths(m, n, P):
    # 初始化dp数组，所有元素初始为0
    dp = [[[0 for _ in range(P + 1)] for _ in range(n + 1)] for _ in range(m + 1)]
    
    # 起点
    dp[1][1][1] = 1
    
    # 填充dp数组
    for p in range(2, P + 1):
        for x in range(1, m + 1):
            for y in range(1, n + 1):
                if x == 1 and y == 1:
                    continue  # 跳过起点
                # 对每一个方向进行累加
                if x > 1:
                    dp[x][y][p] += dp[x - 1][y][p - 1]
                if x < m:
                    dp[x][y][p] += dp[x + 1][y][p - 1]
                if y > 1:
                    dp[x][y][p] += dp[x][y - 1][p - 1]
                if y < n:
                    dp[x][y][p] += dp[x][y + 1][p - 1]
    
    # 最终结果为到达 (m, n) 恰好经过 P 个站点的路径数
    return dp[m][n][P]

# 处理输入
m, n, P = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(m)]

# 计算并输出结果
result = count_paths(m, n, P)
print(result)
