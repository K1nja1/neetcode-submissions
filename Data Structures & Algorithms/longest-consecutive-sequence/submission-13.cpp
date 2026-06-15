class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int max=0;
        for(auto x:st) {
            if(st.find(x-1)==st.end()) {
                int c=1;
                int current=x;
                while(st.find(current+1)!=st.end()) {
                    current++;
                    c++;
                }
                max=max>c?max:c;
            }
        }
        return max;
    }
};
