/**
 * @name 239.滑动窗口最大值
 * @details
 * @url https://leetcode.cn/problems/sliding-window-maximum/description/
 * @idea
 * 优先队列维护滑动窗口内的最大值，不断取堆顶元素。注意要不断弹出堆顶元素以确保堆中都是滑动窗口内的元素
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int size = nums.size();
        priority_queue<pair<int, int>> heap; // value,index

        for (int i = 0; i < k; i++) { heap.emplace(nums[i], i); }

        vector<int> ans;
        ans.push_back(heap.top().first);
        for (int i = k; i < size; i++)
        {
            heap.emplace(nums[i], i);
            while (heap.top().second <= i - k) // ensure the numbers in head exist in window
            {
                heap.pop();
            }
            int top_num = heap.top().first;
            ans.push_back(top_num);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) { Solution s; }