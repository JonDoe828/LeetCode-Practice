/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         int lenA = 0, lenB = 0;
//         ListNode* curA = headA;
//         ListNode* curB = headB;
//         while (curA) {
//             lenA++;
//             curA = curA->next;
//         }
//         while (curB) {
//             lenB++;
//             curB = curB->next;
//         }
//         curA = headA;
//         curB = headB;

//         if (lenA > lenB) {
//             int diff = lenA - lenB;
//             while (diff--) {
//                 curA = curA->next;
//             }
//         } else {
//             int diff = lenB - lenA;
//             while (diff--) {
//                 curB = curB->next;
//             }
//         }

//         while (curA != nullptr && curB != nullptr) {
//             if (curA == curB) {
//                 return curA;
//             }
//             curA = curA->next;
//             curB = curB->next;
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};