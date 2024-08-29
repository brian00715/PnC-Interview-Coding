/**
 * @name 92[M]. 反转链表 II
 * @details
 * @url https://leetcode.cn/problems/reverse-linked-list-ii/
 * @idea 切断后反转再重连。或者一次取三个节点，不断把下一个节点插到开头。
 * @note
 */
#include "../header.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(); // use dummy since left may be 0
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }
        ListNode *curr = pre->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}