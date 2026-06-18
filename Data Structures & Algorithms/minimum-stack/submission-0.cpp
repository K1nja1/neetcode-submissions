class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() { 
        
    }
    
    void push(int val) {
        if(!st.empty() && val>st.back().second) st.push_back({val,st.back().second});
        else st.push_back({val,val});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
       return st.back().first;
    }
    
    int getMin() {  
        return st.back().second;
    }
};
