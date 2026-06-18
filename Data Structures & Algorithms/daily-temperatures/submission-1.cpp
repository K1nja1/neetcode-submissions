class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tsize=temperatures.size();
        vector<int> res(tsize,0);
        stack<int> st;
        for(int i=0;i<tsize;i++){
            int t=temperatures[i];
            while(!st.empty() && t>temperatures[st.top()]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
