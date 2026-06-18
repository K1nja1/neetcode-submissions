class MinStack {
public:
    stack<long long> st;
    long long minel;

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minel = val;
        }
        else if (val >= minel) {
            st.push(val);
        }
        else {
            st.push(2LL * val - minel);
            minel = val;
        }
    }

    void pop() {
        long long t = st.top();
        st.pop();

        if (t < minel)
            minel = 2 * minel - t;
    }

    int top() {
        long long t = st.top();
        if (t < minel)
            return (int)minel;
        return (int)t;
    }

    int getMin() {
        return (int)minel;
    }
};