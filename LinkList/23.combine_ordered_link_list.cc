

#include "../header.hpp"

class Solution
{
public:
    ListNode *combineList(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy_node = new ListNode(-1, nullptr);
        ListNode *tmp = dummy_node;

        ListNode *p1 = l1,
                 *p2 = l2;
        while (p1 != nullptr && p2 != nullptr)
        {

            ListNode *new_node = new ListNode(-1, nullptr);
            if (p1->val < p2->val)
            {
                new_node->val = p1->val;
                p1 = p1->next;
            }
            else
            {
                new_node->val = p2->val;
                p2 = p2->next;
            }
            tmp->next = new_node;
            tmp = new_node;
        }
        // must exist a list that has not been fullty traversed
        if (p1 == nullptr)
        {
            tmp->next = p2;
        }
        else
        {
            tmp->next = p1;
        }
        return dummy_node->next; // return head pointer
    }
};

int main(int argc, char const *argv[])
{

    vector<int> input1{
        45, 68, 74, 77, 78};
    vector<int> input2{
        4, 19, 71, 90, 94};
    ListNode l1(input1);
    ListNode l2(input2);
    // l1.printList();
    // l2.printList();
    Solution s;
    ListNode *rst = s.combineList(&l1, &l2);
    rst->printList();
    return 0;
}
