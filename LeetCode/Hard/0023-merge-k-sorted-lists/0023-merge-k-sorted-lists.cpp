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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return divide(lists, 0, n - 1);
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        // 1. 递归出口
        if (l > r)
            return nullptr;
        if (l == r)
            return lists[l];
        // 2. 找中点 mid
        int mid = l + (r - l) / 2;

        // 3. 左半 [l, mid] 合成一条，右半 [mid+1, r] 合成一条
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);

        // 4. merge 这两条
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        cur->next = left ? left : right;
        return dummy.next;
    }
};