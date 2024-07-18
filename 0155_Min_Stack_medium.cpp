class MinStack {
private:
    stack<int> all_data;
    stack<int> min_data;

public:
    MinStack() {
    }
    
    void push(int val) {
        all_data.push(val);
        val = min(val, min_data.empty() ? val : min_data.top());
        min_data.push(val);
    }
    
    void pop() {
        all_data.pop();
        min_data.pop();
    }
    
    int top() {
        return all_data.top();
    }
    
    int getMin() {
        return min_data.top();
    }
};
