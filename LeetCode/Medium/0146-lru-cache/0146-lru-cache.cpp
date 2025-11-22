// class LRUCache {
//     int capacity_;
//     list<int> keyList_;
//     unordered_map<int, pair<int, list<int>::iterator>> hashMap_;

//     void Insert(int key, int value) {
//         keyList_.push_back(key);
//         hashMap_[key] = make_pair(value, --keyList_.end());
//     }

// public:
//     LRUCache(int capacity) { capacity_ = capacity; }

//     int get(int key) {
//         auto it = hashMap_.find(key);
//         if (it != hashMap_.end()) {
//             keyList_.erase(it->second.second);
//             keyList_.push_back(key);
//             hashMap_[key].second = (--keyList_.end());
//             return it->second.first;
//         }
//         return -1;
//     }

//     void put(int key, int value) {
//         if (get(key) != -1) {
//             hashMap_[key].first = value;
//             return;
//         }
//         if (hashMap_.size() < capacity_) {
//             Insert(key, value);
//         } else {
//             int removeKey = keyList_.front();
//             keyList_.pop_front();
//             hashMap_.erase(removeKey);
//             Insert(key, value);
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp; // key -> 节点指针
    Node* head;                   // 虚拟头
    Node* tail;                   // 虚拟尾

    // 把一个节点移动到链表头（表示这个节点刚被使用）
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    // 从链表中移除节点（不 delete，只断链）
    void removeNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    // 把节点插到 head 后面
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 弹出尾部真实节点（返回这个节点指针，调用者负责 delete）
    Node* removeTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        // 简单释放链表节点，防止内存泄漏（leetcode 不要求，但写上更规范）
        Node* cur = head;
        while (cur) {
            Node* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        }
        Node* node = it->second;
        // 访问了一次，变成最近使用：挪到表头
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // 已存在：更新值，并挪到表头
            Node* node = it->second;
            node->value = value;
            moveToHead(node);
        } else {
            // 不存在：新建节点
            if ((int)mp.size() == capacity) {
                // 容量满了，先淘汰一个尾节点
                Node* old = removeTail();
                mp.erase(old->key);
                delete old;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            addToHead(node);
        }
    }
};