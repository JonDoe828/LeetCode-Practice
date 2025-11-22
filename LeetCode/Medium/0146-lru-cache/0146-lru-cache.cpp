class LRUCache {
    int capacity_;
    list<int> keyList_;
    unordered_map<int, pair<int, list<int>::iterator>> hashMap_;

    void Insert(int key, int value) {
        keyList_.push_back(key);
        hashMap_[key] = make_pair(value, --keyList_.end());
    }

public:
    LRUCache(int capacity) { capacity_ = capacity; }

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it != hashMap_.end()) {
            keyList_.erase(it->second.second);
            keyList_.push_back(key);
            hashMap_[key].second = (--keyList_.end());
            return it->second.first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hashMap_[key].first = value;
            return;
        }
        if (hashMap_.size() < capacity_) {
            Insert(key, value);
        } else {
            int removeKey = keyList_.front();
            keyList_.pop_front();
            hashMap_.erase(removeKey);
            Insert(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

