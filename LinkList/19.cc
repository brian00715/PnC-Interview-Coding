/**
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solutions/450350/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 三种方法：
 * 1. 计数法： 遍历一遍链表得到总长度l，然后第二次遍历到l-n的位置删除节点。时间O(N)，空间O(1)
 * 2. 栈: 遍历节点时入栈，出栈时统计个数到n，删除节点。时间O(N)，空间O(N)
 * 3. 双指针：两个指针遍历，第一个指针比第二个指针领先n个节点，这样第一个指针到末尾的时候第二个指针刚好就是带删除元素。时间O(N)，空间O(1)
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
    ListNode *removeNthFromEndStk(ListNode *head, int n)
    {
        stack<ListNode *> stk;
        ListNode dummy{0, head};
        ListNode *p = &dummy;
        while (p != nullptr)
        {
            stk.push(p);
            p = p->next;
        }
        for (int i = 0; i < n - 1; i++)
        {
            stk.pop();
        }
        ListNode *tmp = stk.top(); // node to be del
        stk.pop();
        ListNode *prev_node = stk.top();
        prev_node->next = tmp->next;
        delete tmp;
        return dummy.next;
    }

    ListNode *removeNthFromEndDoublePtr(ListNode *head, int n)
    {
        ListNode dummy{0, head};
        ListNode *first = &dummy;
        ListNode *second = &dummy;
        for (int i = 0; i < n + 1; i++)
        {
            first = first->next;
        }
        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        // second now points to the prev node of the node to be del
        ListNode *to_be_del = second->next;
        second->next = second->next->next;
        delete to_be_del;
        return dummy.next;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> input = {
        1, 2, 3, 4, 5};
    ListNode *ln = new ListNode{input};
    ln->printList();
    Solution s;
    // ln = s.removeNthFromEndStk(ln, 5);
    ln = s.removeNthFromEndDoublePtr(ln, 2);
    ln->printList();
    return 0;
}
