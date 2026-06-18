class MinStack {
public:
    stack<long long> st;
    long long minel=INT_MAX;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {st.push(val); minel=val;}
        else if (val>=minel) st.push(val);
        else {
            long long encoded= 2LL*val-minel;
            st.push(encoded);
            minel=val;
        }

    }
    
    void pop() {
        long long top=st.top();
        st.pop();
        if(top<minel) minel=2*minel-top;
    }
    
    int top() {
        if(st.top()<minel) return minel;
        else return st.top();
    }
    
    int getMin() {
        if(!st.empty()) return minel;
        else return -1;
    }
};
