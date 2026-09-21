class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minQue;
    int k;
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums)
            add(x);
    }

    int add(int val) {
        minQue.push(val);
        if (minQue.size() > k)
            minQue.pop();

        return minQue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */