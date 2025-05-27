class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {
        min=LLONG_MAX;
        
    }
    
    void push(int val) {
        long long x=(long long)val;
        if(st.size()==0){
            st.push(val);
            min=val;
        }
        else if(val<min){
            st.push(val+(val-min));
            min=val;

        }
        else st.push(val);
        
    }
    
    void pop() {
        if(st.top()<min) min=2*min-st.top();
        st.pop();
        
    }
    
    int top() {
        if(st.top()<min) return min;
        else return st.top();
        
    }
    
    int getMin() {
        return min;
        
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