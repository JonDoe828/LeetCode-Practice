class MyStack {
    std::queue<int> que;

public:
    MyStack() {}

    void push(int x) {
        que.push(x);
        int sz = (int)que.size();
        while (sz-- > 1) { // 旋转 size-1 次
            que.push(que.front());
            que.pop();
        }
    }

    int pop() {
        int ret = que.front();
        que.pop();
        return ret;
    }

    int top() { return que.front(); }

    bool empty() { return que.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */