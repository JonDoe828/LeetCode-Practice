class MinStack {
public:
    std::stack<int> St;
    std::stack<int> minSt;

    MinStack() {}

    void push(int value) {
        if (minSt.empty() || minSt.top() > value) {
            minSt.push(value);
        } else {
            minSt.push(minSt.top());
        }
        St.push(value);
    }

    void pop() {
        minSt.pop();
        St.pop();
    }

    int top() { return St.top(); }

    int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */