/**
 * @name 215[M].数组中的第 K 个最大元素（top k
 * @details
 * @url https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 * @idea 桶排序或者选择性快速排序：只关心pivot，如果pivot刚好就是k就返回,
 * 否则根据pivot和n-k的关系决定下一个子数组的范围
 * @note
 */
#include "../header.hpp"

// 极端案例会超时
class Solution1
{
public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        return quickselect(nums, 0, nums.size() - 1, k);
    }

private:
    int quickselect(std::vector<int> &nums, int left, int right, int k)
    {
        // 使用快速排序的划分方式
        int pivotIndex = partition(nums, left, right);

        // 找到第 k 大的元素
        if (pivotIndex == nums.size() - k) { return nums[pivotIndex]; }
        else if (pivotIndex > nums.size() - k)
        {
            return quickselect(nums, left, pivotIndex - 1, k);
        }
        else { return quickselect(nums, pivotIndex + 1, right, k); }
    }

    int partition(std::vector<int> &nums, int left, int right)
    {
        // 使用最左边的元素作为pivot
        int pivot = nums[left];
        int i = left + 1;
        int j = right;

        while (true)
        {
            while (i <= j && nums[i] <= pivot)
                i++;
            while (i <= j && nums[j] > pivot)
                j--;
            if (i >= j) break;
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[left], nums[j]);

        return j;
    }
};

// 官方题解，省略了partition函数，加速递归
class Solution
{
public:
    int quickselect(vector<int> &nums, int l, int r, int k)
    {
        if (l == r) return nums[k];
        int pivot = nums[l], i = l - 1, j = r + 1;
        while (i <= j)
        {
            while (i <= j && nums[i] < pivot)
                i++;

            while (i <= j && nums[j] > pivot)
                j--;

            if (i <= j)
            {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if (k <= j)
            return quickselect(nums, l, j, k);
        else
            return quickselect(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int res = s.findKthLargest(vec, 4);
    cout << res;
    return 0;
}