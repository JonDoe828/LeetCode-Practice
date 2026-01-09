/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        Node* cur = root; // 当前层的起点（通过 next 横向走）

        while (cur) {
            Node dummy(0);       // 下一层虚拟头
            Node* tail = &dummy; // 下一层尾指针

            // 扫描当前层：cur 通过 next 横向移动
            for (Node* p = cur; p; p = p->next) {
                if (p->left) {
                    tail->next = p->left;
                    tail = tail->next;
                }
                if (p->right) {
                    tail->next = p->right;
                    tail = tail->next;
                }
            }

            // 下一层的起点就是 dummy.next
            cur = dummy.next;
        }
        return root;
    }
};