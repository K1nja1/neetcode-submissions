class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prevS(heights.size(),-1);
        vector<int> nextS(heights.size(),heights.size());
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                nextS[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                prevS[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int maxArea=0;
        for(int i=0;i<heights.size();i++){
            int width= nextS[i]-prevS[i]-1;
            int area=width*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
