
/**
 * @file 206.reverse_link_list.cpp
 * @author SimonKenneth (smkk00715@gmail.com)
 * @brief https://leetcode.cn/problems/reverse-linked-list/solutions/
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
    ListNode *reverseLinkListStack(ListNode *head)
    {
        stack<ListNode *> tmp_stack;
        ListNode *p = head;
        while (p != nullptr)
        {
            tmp_stack.push(p);
            p = p->next;
        }
        ListNode *dummy = new ListNode(0, nullptr);
        ListNode *tmp = dummy;
        while (!tmp_stack.empty())
        {
            ListNode *top = tmp_stack.top();
            tmp_stack.pop();
            /**
             * @note the following code will result in recurrent construction
             *
             * tmp->next = top;
             * tmp = top;
             */
            top->next = nullptr; // this step is very important
            tmp->next = top;
            tmp = top;
        }
        return dummy->next;
    }

    /**
     * @brief 头插法，即每次将新遍历到的元素插入到链接的头部，实现倒序
     *
     * @param list
     * @return ListNode*
     */
    ListNode *reverseLinkListHeadInsert(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        for (ListNode *curr = head; curr; curr = curr->next)
        {
            ListNode *p = new ListNode(curr->val, curr->next);
            p->next = dummy->next;
            dummy->next = p;
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input{
        4, 19, 71, 90, 94};
    ListNode list(input);
    list.printList();
    Solution s;
    // ListNode *rst = s.reverseLinkListStack(&list);
    ListNode *rst = s.reverseLinkListHeadInsert(&list);
    rst->printList();
    return 0;
}
