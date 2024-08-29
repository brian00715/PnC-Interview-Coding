# PnC Interview Coding

[toc]

规划控制相关岗位高频代码题整理与参考答案。

建议刷题顺序：LeetCode Hot 100 -> 代码随想录 -> 剑指 offer。

## 使用说明

在 `header.hpp`中已包含刷题常用的头文件和命名空间，实现了一些常用的数据结构和算法。
在 `.vscode`中已经配置好了基于 clang 的 vscode 调试环境和快捷命令。输入 `lcsol`即可生成一个新的 leetcode 答题模板。

- 清理 clang 编译文件: `python clean.py`
- 统计代码文件与行数: `bash ./count.sh`

自动驾驶公司特别喜欢考察动态规划和、二叉树和图论的题目，可重点准备。

## Array

- 打印类

  - [x] [54[M]. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)
  - [x] [48[M]. 旋转图像](https://leetcode.cn/problems/rotate-image/). 先水平翻转再对角线翻转
  - [ ] [498[M]. 对角线遍历](https://leetcode.cn/problems/diagonal-traverse/)

- 区间类

  - [x] [56[M]. 合并区间](https://leetcode.cn/problems/merge-intervals/). 按照左端点排序，遍历所有区间根据规则判断是否和上一个合并
  - [x] [57[M]. 插入区间](https://leetcode.cn/problems/insert-interval/). 不断取区间和给定区间的并集，直到新区间和原区间断开（也就是 right < li）的时候将新区间插入
  - [x] [435[M].无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/). 本质和 300.最长上升子序列一样。动态规划,等价于选择数量最多的互不重叠的区间, dp[i]表示以第 i 个区间结束不重叠的最大区间数量

- 双指针类

  - [x] [88[E]. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)。直接合并后再重新排序或使用双指针：用辅助数组，每次取更小的放到数组中。或者可以用逆序双指针，从尾部开始每次把最大的放到 array1 里，这样不用辅助数组。
  - [x] [15[M]. 三数之和](https://leetcode.cn/problems/3sum/).核心思路是仍然是三重循环，但只枚举有序的三元组，并使用双指针避免重复枚举
  - [ ] [18[M]. 四数之和](https://leetcode.cn/problems/4sum/).
  - [ ] [11[M]. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/). 每次移动更矮的柱子，迭代最大值

- 二分法

  - [x] [35[E].搜索插入位置](https://leetcode.cn/problems/search-insert-position/). 二分法秒了
  - [x] [162[M].寻找峰值](https://leetcode.cn/problems/find-peak-element/). 二分查找，根据单调性迭代搜索区间
  - [x] [33[M].搜索旋转排列数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/). 选择性二分查找，根据 mid 所在位置判断左右两边哪边是有序的，并判断 target 值和左右区间边界值的大小来更新二分查找的边界
  - [x] [153[M].寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)。二分查找，可以画图判断 pivot 和边界的递推关系
  - [ ] [4[H].寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)。暴力方式是合并后排序。二分法
  - [ ] [34[M]. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/). 两次二分查找，分别找起点和终点

- 回溯法

  - [x] [46[M]. 全排列](https://leetcode.cn/problems/permutations/). 递归回溯, 直接操作原数组，分成左右两半，遍历每一位数字，每次把当前数字交换到 idx 处，相当于固定开头，不重复地组合剩余的数字
  - [x] [77[M]. 组合](https://leetcode.cn/problems/combinations/). 递归回溯。
  - [x] [86[M]. N 皇后问题](). 回溯法，注意回溯时的状态恢复。注意分析递推条件：列不被占用、左上方不被占用、右上方不被占用。对角线的判断可以用行号和列号之差/和来表示

- [ ] [888[E].公平的糖果交换](https://leetcode.cn/problems/fair-candy-swap/)
- [x] [121[E].买股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)。记录最低点，求每天价格和最低点差值的最大值
- [x] [215[M].数组中的第 K 个最大元素（top k）](https://leetcode.cn/problems/kth-largest-element-in-an-array/). 桶排序或者选择性快速排序：只关心 pivot，如果 pivot 刚好就是 k 就返回
- [ ] [209[M]. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/). 暴力枚举。可以用滑动窗口优化，如果 sum < target 则 right++，否则 left++
- [x] [73[M].矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/). 用额外的两个 vector 作为行列标记，每遍历到 0 就标记，再遍历一次数组置零。（建议）可以只用第一行和第一列标记 0，但需要额外的两个变量标记第一行第一列本身是否包含 0。也可以只用一个变量标记第一行第一列是否有 0
- [ ] [877[M]. 石子游戏](https://leetcode.cn/problems/stone-game/)
- [ ] [1140[M]. 石子游戏 2](https://leetcode.cn/problems/stone-game-ii/solutions/2125131/shi-zi-you-xi-ii-by-leetcode-solution-3pwv/)
- [ ] [4[H].寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/)。暴力方式是合并后排序。二分法
- [ ] [85[H].最大矩形](https://leetcode.cn/problems/maximal-rectangle/)
- [ ] [1723[H]. 完成所有工作的最短时间](https://leetcode.cn/problems/find-minimum-time-to-finish-all-jobs/).

## DP

题型总结：简单递推；加判断；加 min/max；加边界条件; 分情况讨论

### 1 路径/矩阵问题

- [x] [62[E].不同路径](https://leetcode.cn/problems/unique-paths/)（机器人走格子）.动态规划， 注意第一行和第一列的初始化
- [x] [63[M].不同路径 2](https://leetcode.cn/problems/unique-paths-ii/). 可以用状态压缩变为一维 dp，从上到下继承，从左到右累加
- [x] [64[M].最小路径和](https://leetcode.cn/problems/minimum-path-sum/)。62 的升级版，加上了 min 操作。注意 cost 给 dp 的赋值方式
- [x] [70[E].爬楼梯](https://leetcode.cn/problems/climbing-stairs/)。动态规划，递归解更简洁。可以只存 3 个数用滑动窗口优化空间复杂度
- [x] [746[E].最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs/). 注意 dp 存的是累积费用而不是方案数量。注意初始化 dp[0] 和 dp[1] 为 0
- [x] [120[M].三角形最短路径和](https://leetcode.cn/problems/triangle/)。跟 64 一样，注意特殊的初始化和状态转移就行
- [x] [221[M].最大正方形](https://leetcode.cn/problems/maximal-square/). 跟 1277 一样，状态转移方程完全一致，改一下统计方式，注意输入的是 char 不是 int
- [x] [1277[M]. 统计全为 1 的正方形子矩阵](https://leetcode.cn/problems/count-square-submatrices-with-all-ones/). dp[i][j]表示坐标 i,j 处的最大正方形数量，状态转移考虑左上角 3 个格子的正方形数量，取 min（由于木桶效应）。
- [x] [790[M].多米诺和拖米诺平铺](https://leetcode.cn/problems/domino-and-tromino-tiling/). 二维动态规划，dp[i][s]表示铺到第 i 列的时候状态 s 的铺法数量，要根据 s=0123 四种情况分类讨论状态转移

### 2 背包问题

本质是约束优化问题或线性规划问题。

#### 0-1 背包

- [x] [Kama 46. 携带研究材料](https://kamacoder.com/problempage.php?pid=1046). dp[i][j]表示第 i 个物品放到容量为 j 的背包里的最大收益，外层遍历物品，内层遍历容量。注意只放第一个物品时的初始化。
- [ ] 总预算为 G，共 M 个候选人，给第 i 个人 Ci 的预算能够产生 Vi 的收益，求可能最大的收益（动态规划）： `dp[j]`，表示容量为 `j` 的背包所能获得的最大收益。外层遍历人头，内层遍历预算
  > 进阶：如果 Ci 和 Vi 的关系不是一个固定关系，而是可变的映射，如何解决（没有完整思路，只回答可以采用一些带约束的离散优化算法解决）

#### 完全背包

- [x] [322[M].零钱兑换](https://leetcode.cn/problems/coin-change/)。动态规划，从 0 开始攒总金额，每一步能凑的钱都基于上一步，看这次用什么面值的硬币。设硬币面值为 c_j，F(i)为凑成面值 i 所需的最小硬币数，则状态转移方程为
- [ ] [518[M].零点兑换 2️](https://leetcode.cn/problems/coin-change-ii/)

#### 多重背包

### 3 子序列问题

#### 不连续子序列

- [x] [300[M].最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/). dp[i]=max(dp[i],dp[j]+1), dp[i]为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度. 遍历每个 i 结尾的所有子序列. 注意初始化为 1
- [x] [1143[M].最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence/)dp[i][j] 表示 text 1[0:i] 和 text2[0:j] 的最长公共子序列的长度。
- [x] [583[M].两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings/). 1143 的变种。可以先找最长公共子序列，然后比较两个串的删除次数谁更少。或者可以直接 dp，dp[i][j]表示到串 1 的 i 和串 2 的 j 为止，删除所需的最小次数，递推时判断字符是否相等，如果相等直接递归到子串；否则看删除哪一个串的字符，然后从中找次数最少的
- [x] [718[M].最长重复子数组](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/).dp[i][j] 表示 A[i:] 和 B[j:] 的最长公共前缀，答案为所有 dp[i][j]中的最大值. 如果 A[i] == B[j], dp[i][j] = dp[i -1][j - 1] + 1,否则为 0. i/j 为 0 时单独处理
- [x] [343[M].整数拆分](https://leetcode.cn/problems/integer-break/). dp[i]表示把数字 i 拆解后的最大成乘积，状态转移在不拆、只拆一次和递归拆分中最大的
- [x] [115[H].不同的子序列](https://leetcode.cn/problems/distinct-subsequences/). dp[i][j] 表示在 s[i:] 的子序列中 t[j:] 出现的个数,倒序递推
- [x] [42[H].接雨水](https://leetcode.cn/problems/trapping-rain-water/). DP：第一次遍历找到每个位置左边的最大值，第二次遍历找到每个位置右边的最大值，然后再遍历一次计算每个位置的接雨水量。找最大值的时候用动态转移。也可以用双指针
- [x] [1035[M].不相交的线](https://leetcode.cn/problems/uncrossed-lines/). 本质和 1143 一模一样

#### 连续子序列

- [x] [53[M].最大子序和/最大子数组和](https://leetcode.cn/problems/maximum-subarray/). dp[i] = max(dp[i-1]+nums[i],nums[i]), 注意要打擂台得到最大和
- [x] [152[M].最大乘积子数组](https://leetcode.cn/problems/maximum-product-subarray/)。维护两个 dp，一个 max 一个 min，转移函数包括三项

#### 字符串/回文

- [x] [32[H].最长有效括号](https://leetcode.cn/problems/longest-valid-parentheses/)。DP，dp[i] 表示以下标 i 字符结尾的最长有效括号的长度； 或者用栈（推荐）匹配括号，每次更新长度
- [x] [516[M].最长回文子串](https://leetcode.cn/problems/longest-palindromic-subsequence/). dp(i,j) 表示字符串 s 的第 i 到 j 个字母组成的串是否为回文串, 初始化单个字符是回文，枚举字符串长度，判断 i...j 之间是否是回文。转移时判断当前字符是否相同，若相同则长度是子串+2，否则从让步的两种方式里选最大的。注意外层从
- [x] [647[M].回文子串](https://leetcode.cn/problems/palindromic-substrings/)。中心拓展法，枚举每一个可能的回文中心，然后双指针左右拓展。或者用 DP[i][j]，枚举子串长度，注意 i 倒着遍历，j 正着遍历
- [x] [97[M].交错字符串](https://leetcode.cn/problems/interleaving-string/). dp[i][j]表示 s1 的前 i 个和 s2 的前 j 个能否凑成 s3 的 i+j 个。dp 向后递推,考虑 s1 的前 i-1 和 s2 的前 j 能否凑成 s3 的 i-1+j，s2 同理。 注意初始化方式

### 4 股票问题

- [x] [122[M]. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)
- [ ] [123[H]. 买卖股票的最佳时机 III](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)
- [ ] [188[H]. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)

### 5 打家劫舍

- [x] [198[M].打家劫舍](https://leetcode.cn/problems/house-robber/). dp[i]表示到第 i 间屋子的最大金额，考虑拿这一家+上 2 家还是还是上一家
- [x] [213[M].打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/). 思路沿用 198，由于首尾相连，不能同时偷第一家和最后一家，因此对下标范围进行两种特殊讨论即可，然后取最大的。

## Geometry

- [x] 判断点是否在三角形内部： 三个向量叉乘判断符号，如果是同号（同正或者同负），则在三角形内部
- [ ] 判断多边形凹凸性
- [ ] 手撕凸包计算
- [ ] 判断两条直线是否相交
- [ ] 计算一个点到一条直线的距离

## Graph

- [ ] BFS 找最短路径。注意保留 parent 节点并在最后回溯得到实际路径
- [x] [200[M].岛屿数量](https://leetcode.cn/problems/number-of-islands/). DFS 秒了，注意遍历陆地前判断是否已访问过
- [x] [695[M].最大岛屿面积](https://leetcode.cn/problems/max-area-of-island/). DFS 秒了，注意地图可能不是方形的
- [x] [797[M].图所有可能路径](https://leetcode.cn/problems/all-paths-from-source-to-target/). DFS 找路，用 stack 保存所有路径，注意回溯时的状态恢复(push->DFS->pop)
- [x] [815[H].公交车线路](https://leetcode.cn/problems/bus-routes/). 建图+BFS 搜索。注意建图的时候用 unordered_map 存储每个车站能坐的公交线路，再用二维数组存储表示公交线路之间的连通性。
- [ ] [2685[M].统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components/).（最大连通子图的大小）. 先计算每个节点的度并构建邻居节点集合。遍历每个节点，用 DFS 找联通图，对于一个连通图中的每个节点，如果节点度数都等于图节点数-1，则为完全联通图
- [x] [417[M].太平洋大西洋水流问题/Kama103](https://leetcode.cn/problems/pacific-atlantic-water-flow/). 维护两个 visited，分别从边界开始找路，最后合并结果
- [x] [827[H]. 最大人工岛/Kama 104](https://leetcode.cn/problems/making-a-large-island/). 先遍历一遍，对不同的岛屿做标记并用 map 维护大小。再遍历一遍尝试将每个 cell 变成陆地，然后和周围临近的岛屿（如果有）拼在一起算更大的总面积。
- [ ] [994[M]. 腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/). 多源 BFS,矩阵维护时间，cnt 维护剩余橘子数
- [ ] [127[H]. 单词接龙](https://leetcode.cn/problems/word-ladder/)。每个中间字符串当作一个节点，用 BFS 搜索
- [x] [2290[H].到达角落需要移除障碍物的最小数目](https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/). 把所有路都视为可通行的，障碍物视为代价，bfs 搜索。注意用标记 visited 避免超时

## Hashtable

- [x] [1[E].两数之和](https://leetcode.cn/problems/two-sum/)。暴力两个 for 或者用哈希表找 target-x

## Link List

- [x] [21[E]. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)
- [x] [206[E].反转链表](https://leetcode.cn/problems/reverse-linked-list/). 利用栈或头插法，务必注意哑节点的使用和边界条件
- [x] [92[M]. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/). 切断后反转再重连。或者一次取三个节点，不断把下一个节点插到开头。
- [x] [19[M]. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/). 利用栈或双指针（快慢指针）
- [x] [141[E]. 环形链表](https://leetcode.cn/problems/linked-list-cycle/).用哈希表来存储所有已经访问过的节点。每次我们到达一个节点，如果该节点已经存在于哈希表中，则说明该链表是环形链表，否则就将该节点加入哈希表中。重复这一过程
- [x] [328[M]. 奇偶链表](https://leetcode.cn/problems/odd-even-linked-list/). 直接写就完事了，应该算 E 的。注意保存 even_head，偶数更快到 null，因此要作为 while 的结束条件
- [x] [147[M].对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list/). 链表分为有序和乱序，用当前节点遍历前面的有序链表，找到合适的插入位置。注意储存有序链表的末尾，并更新有序链表末尾节点的下一个节点
- [x] [148[M].排序链表](https://leetcode.cn/problems/sort-list/). 147 的升级，要求时间复杂度达到 O logn. 用归并的思想递归切分子链表，再合并有序链表

## Stack & Queue

- [x] [20[M]. 有效的括号](https://leetcode.cn/problems/valid-parentheses/).
- [x] [239[H]. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)。用优先队列, 注意要不断弹出堆顶元素以确保堆顶元素在窗口内
- [ ] [155[M]. 最小栈](https://leetcode.cn/problems/min-stack/)。用一个辅助栈存最小的元素
- [x] [150[M]. 逆波兰表达式](https://leetcode.cn/problems/evaluate-reverse-polish-notation/?envType=study-plan-v2&envId=top-interview-150). 用栈存数字，遇到数字就压入，遇到操作符就连续弹两个数字，算完再压回去，直到遍历完成
- [ ] NC76[M]. 两个栈实现队列

## String

- [ ] [14[E].最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/)
- [ ] [344[E].反转字符串](https://leetcode.cn/problems/reverse-string/)

- 双指针/滑动窗口类

  - [x] [392[E].判断子序列](https://leetcode.cn/problems/is-subsequence/). 贪心匹配+双指针，或者用二维 dp 向后递推 dp[i][j]表示在目标串中从 i 向后字符 j 第一次出现的位置
  - [x] [1100[M]. 长度为 K 的无重复字符子串](https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/description/). 双指针滑动窗口，用 map 统计出现频次，动态移动左右指针
  - [x] [3[M].无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/).滑动窗口，本质和 1100 一样，变成统计最大长度而已
  - [x] [159[M]. 至多包含两个不同字符的最长子串](https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/) 滑动窗口，哈希表存每个字符最右边的下标，一旦窗口内有 3 个不同的字符就删除最左边的，迭代更新最大值
  - [x] [340[M]. 至多包含 K 个不同字符的最长子串](https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters/). 159 的升级版, 思路一样

- [ ] [17[M]. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)/给你若干个 list，从每个 list 中选出一个元素，求全排列？
- [ ] [678[M].有效的括号字符串](https://leetcode.cn/problems/valid-parenthesis-string/).左括号或\*入栈，遇到右括号分情况弹栈
- [ ] [692[M].前 K 个高频单词](https://leetcode.cn/problems/top-k-frequent-words/). 哈希表+排序，注意排序的语法

## Tree

- [x] 三种遍历顺序
- [x] [104[E].二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)。 递归，取左、右子树最大深度的最大值+1
- [x] [102[M].层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal/)。难点是区分每层结果，思想是基于 BFS，根据每层节点的个数用 for 每次一次性遍历一层
- [x] [226[E].翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)。递归翻转，左等右，右等左。要掌握主调函数返回类型分别用 void 和 treenode\*写
- [x] [98[M].验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)
- [x] [236[M].二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)
- [ ] [199[M].二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view/)
- [x] [牛群仰视图](https://www.nowcoder.com/practice/0f37a18320c4466abf3a65819592e8be?tab=note)
- [ ] [124[H].二叉树的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/)
- [ ] [297[H]. 二叉树的序列化与反序列化](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/)
- [ ] [222[E]. 完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/)
- [ ] 给出二叉树的先序遍历和中序遍历，输出后序遍历？
- [ ] [LCR 151[M]. 彩灯装饰记录 III(之字打印二叉树)](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/). 层序遍历+双端队列
- [ ] [106[M]. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/). 重要性质：后序遍历的数组最后一个元素代表的即为根节点
- [ ] [2196[M]. 根据描述创建二叉树](https://leetcode.cn/problems/create-binary-tree-from-descriptions/)
- [ ] [230[M]. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/)
- [ ] [654[M]. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

## Greedy

- [x] [860[E]. 柠檬水找零](https://leetcode.cn/problems/lemonade-change/). 分类讨论+贪心，注意收 20 找零时的顺序，先找 10+5 再找 5x3. 如何用 RL 解？定义 MDP 模型：观测是收的钱，状态是已有的钱，动作是找的钱（5 元和 10 元数量，离散空间），奖励是是否成功找零。可以直接用基于表格的 Q-learning 算法求解，也可以用基于神经网络的 DQN 求解。
- [ ] [2087[M].网格图中机器人回家的最小代价](https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)。由于上下和左右走代价一样，因此不需要 BFS，直接走就行了，先走到家所在行，再走列，累计路上的代价。
- [ ] [55[M].跳跃游戏](https://leetcode.cn/problems/jump-game/)。遍历每个元素，维护当前下标能到达的最远下标，如果当前下标超过了最远下标，说明无法到达，返回 false。如果最远下标超过了数组长度，说明可以到达，返回 true。
- [ ] [45[M].跳跃游戏 2](https://leetcode.cn/problems/jump-game-ii/).
- [ ] [674[E].最长连续递增序列](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)。贪心法

## Numercial Computation

- [ ] [7[M]. 整数反转](https://leetcode.cn/problems/reverse-integer/)
- [x] [50[M]. Pow(x, n)](https://leetcode.cn/problems/powx-n/). 递归计算.注意用 long long 存一下 n。注意区分 n 为奇数和偶数的情况，奇数时要多乘一个 x
- [x] [69[E]. x 的平方根](https://leetcode.cn/problems/sqrtx/)
- [x] 寻找二次曲线（离散点构成）最小值, 同力扣 162
- [x] 已知 lnx+x^2 =0 在（0,1）范围内有唯一解，用数值方法求解，精度 0.0001
- [ ] 写一个四元数转 translation 的代码
- [ ] abs(x – sqrt(A)) < m，A,m 都给了，让求最大的 x,不允许调用数学库
- [x] [手撕矩阵乘法](./NumericalComputation/matrix_multiply.cc)
- [ ] 求矩阵行列式

## Sort/Search

- [ ] [快速排序](./Sort/quick_sort.cc), 包括非递归版本
- [ ] 归并排序
- [ ] 归并排序求逆序对个数，并记录每个元素对应的逆序对个数
- [ ] 实现一个堆排序

## Machine Learning

- [ ] 手撕 kmeans
- [x] 手撕矩阵乘法
- [x] 手撕卷积
- [ ] 手撕 multi head attention
- [ ] 手撕 transformer layer
- [x] 手撕 iou
- [ ] 手撕 nms
- [ ] 手撕 focal loss
- [ ] 手撕 deformable conv

## Image Processing

- 3*3 的卷积核去卷积 128*128 的图片，现在有 64 路运算单元可以并行，怎样运算可以提高效率。

  将 128*128 切成 16*16 个 patch（共 64 个）patch，每个单元计算一个 patch 的卷积，最后合并结果

- 有一个电机可以控制相机移动，相机拍着一个标定板，移动电机找到相机清晰度最高的位置，设计算法实现。

## OS

- [ ] 手撕多线程
- [ ] 写一段多线程访问 shared_ptr 对象会出现问题的代码

## Event Simulation

## Others

- [x] [手撕 unique_ptr](./Others/unique_ptr.cc)
- [x] [手撕 shared_ptr](./Others/shared_ptr.cc)
- [x] [手撕一个 vector](./Others/vector.cc). 注意扩容机制
- [x] 手撕二分查找
- [ ] 找出数组中是否可以实现一半数字和等于另外一半
- [ ] 手写类的继承
- [ ] 类中实现均值滤波
- [ ] 1-26 代表‘A’~‘B’,27 代表‘AA’,28 代表‘AB’，以此类推，给一个整数，输出他表示的字符串。
- [ ] 手撕单例模式
- [ ] 手撕优先级队列（不准用容器）
- [ ] 给一个 01 串，保证开头为 0，结尾为 1，找到任意一个“01”子串的位置，复杂度尽可能低
- [ ] 无向图，给定两节点 a,b，求路径必会经过 a 和 b 的节点对数（分别断开 a 和 b 进行容斥）
- [ ] n 个洞一排，兔子每天往左或右跳一格，每天询问一个洞里是否有兔子，找到一个一定能找出兔子的策略（顺着问一遍再反着问一遍，奇偶性错开）
- [ ] 元戎独创 1

  > Alice 和 Bob 两个人正在玩游戏，轮流操作. Alice 先手.
  > 给定一个非严格递增的非负整数的数组, 每次操作选择一个区间[l,r]全部减一.
  > 条件 1：操作后的数组还是满足非严格递增
  > 条件 2：当数组元素全为 0，则判定失败.
  > 问谁胜利？
  > 输入一个正整数 n, 接下来输入 n 个元素，表示数组内容.
  > 样例:
  > 3
  > 1 1 1
  > 输出：Alice 胜
  > 2
  > 0 2
  > 输出：Bob 胜

- [ ] 元戎独创 2

  > 把数组转化为差分数组.
  > 区间-1 操作，即变成选定下标[i,j] a[i]-1, a[j]+1,全部元素为 0 则失败
  > 用石头的角度来看，对于第 i 堆的每个石头，可以移动 1,2,3,...n+1-i 次.
  > 那么问题就转化成了经典 nim 博弈.
  > ans = 0;
  > a[i]的石头数是奇数，ans^= n+1-i;//a[i]是已经是差分数组了.
  > 最终 ans 为 0，则先手必败，反之，先手必胜.

- [ ] 元戎独创 3

  > 给定 n,m.其中 n<=1e6, m <=1000  
  > 给定一个 n 个元素的非负整数数组，问该数组是否存在一个非空序列，满足序列中的元素之和是 m 的倍数.  
  > 样例：
  > 3 5
  > 5 5 5
  > 输出：YES

## 智力题

- [ ] 1000 桶水有一桶有毒，一头猪喝了有毒的水之后过 15 分钟会死掉，问最少需要多少头猪来找到有毒的水，在一个小时之内？
- [ ] 一块蛋糕切 n 刀最多切几块

  $$
  \frac{n(n+1)}{2} + 1
  $$

- [ ] A，B，C 三个角色，C 告诉 B 生日日期，告诉 A 生日月份，给 10 个日期选项与一些条件，推理 C 的生日是哪一天。

## 概率论

- 2 人抛硬币，正面赢，反面让另一个人抛，求先抛的人获胜的概率？
  设
  $$
  p=\frac{1}{2} \times 1+\frac{1}{2} \times(1-p) \Rightarrow p=\frac{2}{3}
  $$
- 抛硬币，连续两次正面向上为止，求次数期望
- 三个门，门后一个有礼物，你选了一个，帮你排除了一个没有礼物的门，问你换不换
- n 个人，其中一个是明星其余为普通人，明星不认识普通人，普通人都认识明星，普通人之间是否认识未知。现给一个黑盒，可以询问一次 A 是否认识 B，问使用黑盒几次能找到明星？
