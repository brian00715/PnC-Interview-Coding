/**
 * @file 92.reverse_link_list2.cpp
 * @author SimonKenneth (smkk00715@gmail.com)
 * @brief https://leetcode.cn/problems/reverse-linked-list-ii/description/
 * reverse the nodes from the given left to right in a link list
 * @version 0.1
 * @date 2024-01-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "../header.hpp"
class Solution
{
public:
    /**
     * @note notice the application of dummy node. it's very important in this problem to enable successful slicing
     *
     * @param head
     * @param left
     * @param right
     * @return ListNode*
     */
    ListNode *reverseLinkListStack(ListNode *head, int left, int right)
    {
        if (left == right || head->next == nullptr)
        {
            return head;
        }

        stack<ListNode *> stk;
        ListNode *dummy = new ListNode{-1, head};
        ListNode *p = dummy;

        ListNode *sub_list_prev = dummy;
        for (int i = 0; i < left; i++, p = p->next)
        {
            sub_list_prev = p;
        }
        // p = p->next; // note p starts from dummy node, so update once more here
        ListNode *sub_list_end;
        for (int i = 0; i < (right - left) + 1 && p; i++, p = p->next) /** @note don't neglect +1 */
        {
            stk.push(p);
        }
        sub_list_end = p;

        // pop and reverse
        ListNode *dummy2 = new ListNode{};
        p = dummy2;
        for (; !stk.empty();)
        {
            ListNode *top = stk.top();
            stk.pop();
            top->next = nullptr;
            p->next = top;
            p = p->next;
        }
        p->next = sub_list_end;
        sub_list_prev->next = dummy2->next;
        return dummy->next;
    }

    ListNode *reverseLinkListHeadInsert(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;
        for (int i = 0; i < left - 1; i++, p = p->next) // -1 to stop at the previous node
        {
        }
        ListNode *dummy4sub = p;
        ListNode *curr = p->next;
        ListNode *sub_first_node;
        for (int i = 0; i < (right - left) + 1; i++, curr = curr->next) // note +1
        {
            ListNode *tmp = new ListNode(curr->val, curr->next);
            if (i == 0)
            {
                tmp->next = nullptr;
                sub_first_node = tmp;
            }
            else
            {
                tmp->next = dummy4sub->next;
            }
            dummy4sub->next = tmp;
        }
        sub_first_node->next = curr;
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input{
        // 1, 2, 3, 4, 5
        3, 5
        // 1, 2, 3
    };
    ListNode list(input);
    list.printList();
    Solution s;
    // ListNode *rst = s.reverseLinkListStack(&list, 1, 2);
    ListNode *rst = s.reverseLinkListHeadInsert(&list, 1, 2);
    rst->printList();
    return 0;
}
