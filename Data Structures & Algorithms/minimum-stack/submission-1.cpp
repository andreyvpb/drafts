class MinStack {
    struct MSItem{
        int val;
        int min;
    };
    deque<MSItem> sq;
public:
    MinStack():sq() {}
    
    void push(int val) {
        int min = val;
        if (!sq.empty() && sq.back().min < val) {
            min = sq.back().min;
        }
        sq.emplace_back(val, min);
    }
    
    void pop() {
        sq.pop_back();
    }
    
    int top() {
        return sq.back().val;
    }
    
    int getMin() {
        return sq.back().min;
    }
};
