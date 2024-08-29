/**
 * @name 86.N皇后问题
 * @details
 * @url
 * @idea 回溯
 * @note 暴力解法时间复杂度是C_{N^2}^{N}，是一个组合数公式，第一个皇后有N^2个可能的位置，第二个皇后有(N^2-1)个可能的位置，以此类推。
 */
#include "../header.hpp"

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> solutions;
        vector<int> queens = vector<int>(n, -1); // stores the queens' column index for every row
        unordered_set<int> columns;
        unordered_set<int> diag1s;
        unordered_set<int> diag2s;

        backtrack(solutions, queens, n, 0, columns, diag1s, diag2s);
        return solutions;
    }

    /**
     * @brief
     *
     * @param solutions final solutions
     * @param queens a vector that stores the column indexes for queesn at every row.
     * @param n chess board dim
     * @param row row index [0,n-1]
     * @param columns set that stores column index
     * @param diagonals1 set that stores diagonals from up-left to down-right
     * @param diagonals2 set that stores diagonals from down-left to up-eight
     */
    void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row,
                   unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2)
    {
        if (row == n)
        {

            vector<string> solution = genBoard(queens, n);
            solutions.push_back(solution);
        }
        else
        {
            // traverse every column for every row
            for (int i = 0; i < n; i++)
            {
                // check the feasibility for this column
                if (columns.find(i) != columns.end()) // occupied
                {
                    continue;
                }
                int diag1 = row - i;
                if (diagonals1.find(diag1) != diagonals1.end())
                {
                    continue;
                }
                int diag2 = row + i;
                if (diagonals2.find(diag2) != diagonals2.end())
                {
                    continue;
                }

                // every thing is ok, add it!
                queens[row] = i;
                columns.insert(i);
                diagonals1.insert(diag1);
                diagonals2.insert(diag2);
                backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2); // forward to the next row to get the remaining indexed conditioned by current solution
                // cancle the insert operation to garentee the indepency
                queens[row] = -1;
                columns.erase(i);
                diagonals1.erase(diag1);
                diagonals2.erase(diag2);
            }
        }
    }

    vector<string> genBoard(vector<int> queens, int dim)
    {
        vector<string> board;
        for (int i = 0; i < dim; i++)
        {
            string row = string(dim, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> rst = s.solveNQueens(4);
    return 0;
}