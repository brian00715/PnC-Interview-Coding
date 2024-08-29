/**
 * @name 147.对链表进行插入排序
 * @details
 * @url https://leetcode.cn/problems/insertion-sort-list/description/
 * @idea
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head) return nullptr;

        ListNode dummy;
        dummy.next = head;
        ListNode *curr = head->next; // start from 2nd node
        ListNode *last_sorted = head;
        while (curr)
        {
            if (curr->val >= last_sorted->val) { last_sorted = last_sorted->next; }
            else
            {
                ListNode *prev = &dummy;
                while (curr->val >= prev->next->val) // find the suitable insertion pos
                {
                    prev = prev->next;
                }
                // execute insertion
                last_sorted->next = curr->next; // NOTE: may be hard to remember
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = last_sorted->next;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {-1, 5, 3, 4, 0};
    ListNode list1(data);
    list1.printList();
    auto sorted = s.insertionSortList(&list1);
    sorted->printList();
    return 0;
}