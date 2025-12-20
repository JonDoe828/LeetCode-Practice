// class MyLinkedList {
// public:
//     // Define a structure for the linked list node
//     struct LinkedNode {
//         int val;
//         LinkedNode* next;
//         LinkedNode(int val) : val(val), next(nullptr) {}
//     };

//     MyLinkedList() {
//         _dummyHead = new LinkedNode(0); // This defines a dummy head node,
//         not
//                                         // the actual head node of the list.
//         _size = 0;
//     }

//     int get(int index) {
//         if (index > (_size - 1) || index < 0) {
//             return -1;
//         }
//         LinkedNode* cur = _dummyHead->next;
//         while (index--) {
//             cur = cur->next;
//         }
//         return cur->val;
//     }

//     void addAtHead(int val) {
//         LinkedNode* newNode = new LinkedNode(val);
//         newNode->next = _dummyHead->next;
//         _dummyHead->next = newNode;
//         _size++;
//     }

//     void addAtTail(int val) {
//         LinkedNode* newNode = new LinkedNode(val);
//         LinkedNode* cur = _dummyHead;
//         while (cur->next != nullptr) {
//             cur = cur->next;
//         }
//         cur->next = newNode;
//         _size++;
//     }

//     void addAtIndex(int index, int val) {
//         if (index > _size)
//             return;
//         if (index < 0)
//             index = 0;
//         LinkedNode* newNode = new LinkedNode(val);
//         LinkedNode* cur = _dummyHead;
//         while (index--) {
//             cur = cur->next;
//         }
//         newNode->next = cur->next;
//         cur->next = newNode;
//         _size++;
//     }

//     void deleteAtIndex(int index) {
//         if (index >= _size || index < 0) {
//             return;
//         }
//         LinkedNode* cur = _dummyHead;
//         while (index--) {
//             cur = cur->next;
//         }
//         LinkedNode* tmp = cur->next;
//         cur->next = cur->next->next;
//         delete tmp;
//         tmp = nullptr;
//         _size--;
//     }

//     // Print the linked list
//     void printLinkedList() {
//         LinkedNode* cur = _dummyHead;
//         while (cur->next != nullptr) {
//             cout << cur->next->val << " ";
//             cur = cur->next;
//         }
//         cout << endl;
//     }

// private:
//     int _size;
//     LinkedNode* _dummyHead;
// };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* dummy; // 虚拟头
    int sz;

    Node* getPrev(int index) {
        // 返回 index 的前驱：从 dummy 走 index 步
        Node* cur = dummy;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        return cur;
    }

public:
    MyLinkedList() : dummy(new Node(0)), sz(0) {}

    int get(int index) {
        if (index < 0 || index >= sz)
            return -1;
        Node* cur = dummy->next;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(sz, val); }

    void addAtIndex(int index, int val) {
        if (index > sz)
            return;
        if (index < 0)
            index = 0;

        Node* prev = getPrev(index);
        Node* node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        ++sz;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= sz)
            return;

        Node* prev = getPrev(index);
        Node* del = prev->next;
        prev->next = del->next;
        delete del;
        --sz;
    }

    ~MyLinkedList() {
        Node* cur = dummy;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }
};