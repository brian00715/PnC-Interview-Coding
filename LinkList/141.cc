/**
 * @name 141.环形链表
 * @details 判断链表内是否有环
 * @url https://leetcode.cn/problems/linked-list-cycle/description/
 * @idea 构建哈希表记录遍历时是否访问过某个相同的节点，若访问过则表明出现了环
 * @note
 */
#include "../header.hpp"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr) return false;
        unordered_set<ListNode *> visited;
        ListNode *curr_ptr = head;
        while (curr_ptr != nullptr)
        {
            if (visited.count(curr_ptr)) { return true; }
            visited.insert(curr_ptr);
            curr_ptr = curr_ptr->next;
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Test case 1: 无环链表
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    cout << "Test case 1: " << (solution.hasCycle(head1) ? "Cycle detected" : "No cycle")
         << endl; // 应输出 "No cycle"

    // Test case 2: 有环链表
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = head2->next; // 3 -> 2 形成环
    cout << "Test case 2: " << (solution.hasCycle(head2) ? "Cycle detected" : "No cycle")
         << endl; // 应输出 "Cycle detected"

    // Test case 3: 单个节点无环
    ListNode *head3 = new ListNode(1);
    cout << "Test case 3: " << (solution.hasCycle(head3) ? "Cycle detected" : "No cycle")
         << endl; // 应输出 "No cycle"

    // Test case 4: 单个节点自环
    ListNode *head4 = new ListNode(1);
    head4->next = head4; // 自环
    cout << "Test case 4: " << (solution.hasCycle(head4) ? "Cycle detected" : "No cycle")
         << endl; // 应输出 "Cycle detected"

    // Test case 5: 空链表
    ListNode *head5 = nullptr;
    cout << "Test case 5: " << (solution.hasCycle(head5) ? "Cycle detected" : "No cycle")
         << endl; // 应输出 "No cycle"

    return 0;
}