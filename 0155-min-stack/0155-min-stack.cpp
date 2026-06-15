class MinStack {
public:
    int MinVal;
    stack<long long> st;
    //encode if new min value storeed
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value); MinVal = value;
            return;
        }
        else if(value >= MinVal){
            st.push(value);
        }
        else{
            //smaller than MinVal
            //we need to store the current MINVAL..encode it
            st.push(2LL*value - MinVal);
            MinVal = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long val = st.top(); st.pop();
        if(val < MinVal){
            MinVal = 2LL*MinVal - val;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long val = st.top();
        if(val < MinVal){
            return MinVal;
        }
        else{
            return (int)val;
        }
    }
    
    int getMin() {
        if(st.empty()) return -1;

        return MinVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */