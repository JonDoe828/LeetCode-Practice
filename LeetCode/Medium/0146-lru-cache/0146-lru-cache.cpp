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
        auto it = hashMap_.find(key);

        if (it != hashMap_.end()) {
            keyList_.erase(it->second.second);
            keyList_.push_front(key);

            hashMap_[key] = make_pair(value, keyList_.begin());
            return;
        }

        if (hashMap_.size() == capacity_) {
            hashMap_.erase(keyList_.back());
            keyList_.pop_back();
        }

        insert(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */