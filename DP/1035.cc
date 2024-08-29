/**
 * @name 1035[M].不相交的线
 * @details
 * @url
 * @idea 和1143不相交的线本质是一样的,题解都一模一样
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1]) { dp[i][j] = dp[i - 1][j - 1] + 1; }
                else { dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); }
            }
        }
        return dp[n1][n2];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}