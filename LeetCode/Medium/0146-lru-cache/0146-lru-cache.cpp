class LRUCache {
    int capacity_;
    list<int> keyList_;
    unordered_map<int, pair<int, list<int>::iterator>> hashMap_;

    void insert(int key, int value) {
        keyList_.push_front(key);
        hashMap_[key] = make_pair(value, keyList_.begin());
    }

public:
    LRUCache(int capacity) { capacity_ = capacity; }

    int get(int key) {
        auto it = hashMap_.find(key);
        if (it == hashMap_.end()) {
            return -1;
        }

        keyList_.erase(it->second.second);
        keyList_.push_front(key);
        hashMap_[key].second = (keyList_.begin());

        return it->second.first;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hashMap_[key].first = value;
            return;
        }
        if (hashMap_.size() < capacity_) {
            insert(key, value);
        } else {
            int removeKey = keyList_.back();
            keyList_.pop_back();
            hashMap_.erase(removeKey);
            insert(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */