class MinStack {
public:
    vector<long long> st;
    long long minel;
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {st.push_back(val); minel=val;}
        else if (val>=minel) st.push_back(val);
        else {
            long long encoded= 2LL*val-minel;
            st.push_back(encoded);
            minel=val;
        }

    }
    
    void pop() {
        long long top=st.back();
        st.pop_back();
        if(top<minel) minel=2*minel-top;
    }
    
    int top() {
        if(st.back()<minel) return minel;
        else return st.back();
    }
    
    int getMin() {
        if(!st.empty()) return minel;
        else return -1;
    }
};
