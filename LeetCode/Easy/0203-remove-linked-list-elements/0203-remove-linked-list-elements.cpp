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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = &dummy;

        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* toDelete = cur->next;      // 先保存要删的节点
                cur->next = cur->next->next;
                delete toDelete;                      // 再释放内存
            } else {
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};