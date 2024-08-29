/**
 * @name 88.合并两个有序数组
 * @details
 * @url https://leetcode.cn/problems/merge-sorted-array/solutions/666608/he-bing-liang-ge-you-xu-shu-zu-by-leetco-rrb0/
 * @idea
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1=m-1,p2=n-1;
        int tail = m+n-1;
        while(p1>=0 && p2>=0)
        {
            if(nums1[p1]>nums2[p2])
            {
                nums1[tail--] = nums1[p1--];
            }
            else if (nums1[p1]<=nums2[p2])
            {
                nums1[tail--] = nums2[p2--];
            }
        }
        if(p1==-1)
        {
            while(p2>=0)
            {
                nums1[tail--] = nums2[p2--];
            }
        }
        else
        {
            while(p1>=0)
            {
                nums1[tail--] = nums1[p1--];
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
}