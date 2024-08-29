/**
 * @name binary search
 * @details
 * @url
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    int binSearch(vector<int> &ar, int target_num)
    {
        int n = ar.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (ar[mid] > target_num) { right = mid - 1; }
            else if (ar[mid] < target_num) { left = mid + 1; }
            else { return mid; }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> ar = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int idx = s.binSearch(ar, 5);
    cout << idx << endl;
    idx = s.binSearch(ar, 11);
    cout << idx << endl;
    idx = s.binSearch(ar, 19);
    cout << idx << endl;
}