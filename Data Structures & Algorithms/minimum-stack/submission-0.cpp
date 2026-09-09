class MinStack {
    struct MSItem{
        int val;
        int min;
    };
    deque<MSItem> sq;
public:
    MinStack():sq() {
        
    }
    
    void push(int val) {
        int min = val;
        if (!sq.empty() && sq.back().min < val) {
            min = sq.back().min;
        }
        //cout << "push {" << val << "," << min << "}" << endl;
        sq.push_back(MSItem{val, min});
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
