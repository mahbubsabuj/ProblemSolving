// Space Complexity : O(2 * N)

class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(make_pair(val, val));
        } else {
            st.push(make_pair(val, min(st.top().second, val)));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Space Complexity : O(N)

class MinStack {
public:
    stack<long long> st;
    long long current_min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            current_min = val;
            st.push(val);
        } else {
            if (val > current_min) {
                st.push(val);
            } else {
                st.push((long long) 2 * val - current_min);
                current_min = val;
            }
        }
    }
    
    void pop() {
        if (st.top() < current_min) {
            current_min = (long long) 2 * current_min - st.top();
        }
        st.pop();
    }
    
    int top() {
        if (st.top() < current_min) {
            return (int) current_min;
        } else {
            return (int) st.top();
        }
    }
    
    int getMin() {
        return (int) current_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */