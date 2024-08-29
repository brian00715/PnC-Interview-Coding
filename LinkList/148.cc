/**
 * @name 148.排序链表
 * @details
 * @url https://leetcode.cn/problems/sort-list/description/
 * @idea 归并排序，用快慢指针找中点，递归调用，写辅助链表合并函数
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
    ListNode *sortList(ListNode *head)
    {
        return recursiveSortList(head, nullptr);
    }

    ListNode *recursiveSortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr) return nullptr;
        if (head->next == tail) // only two nodes
        {
            head->next = nullptr;
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        int cnt = 0;
        while (fast != tail)
        {
            // NOTE: The following block is much slower
            // fast = fast->next;
            // if (cnt % 2 == 0)
            // {
            //     slow = slow->next;
            //     cnt++;
            // }

            slow = slow->next;
            fast = fast->next;
            if (fast != tail) { fast = fast->next; }
        }
        ListNode *rst = mergeSorted(recursiveSortList(head, slow), recursiveSortList(slow, tail));
        return rst;
    }

    ListNode *mergeSorted(ListNode *l1, ListNode *l2)
    {
        ListNode merged;
        ListNode *curr1 = l1, *curr2 = l2;
        ListNode *curr_merge = &merged;
        while (curr1 != nullptr && curr2 != nullptr)
        {
            if (curr1->val < curr2->val)
            {
                curr_merge->next = curr1;
                curr_merge = curr1;
                curr1 = curr1->next;
            }
            else
            {
                curr_merge->next = curr2;
                curr_merge = curr2;
                curr2 = curr2->next;
            }
        }
        if (curr1) { curr_merge->next = curr1; }
        else { curr_merge->next = curr2; }
        return merged.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {-1, 5, 3, 4, 0};
    ListNode list1(data);
    list1.printList();
    auto sorted = s.sortList(&list1);
    sorted->printList();
    return 0;
}