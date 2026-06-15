class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int left=0;
        int right=1;

        int count=1;
        unordered_map<char,int> st;
        st[s[left]]=left;
        while(right<s.size() && left<right){
            if( st.find(s[right]) != st.end() && left<=st[s[right]]) { left=st[s[right]]+1;}
            st[s[right]]=right;  count=max(count,right-left+1); right++; 
        }
        return count;
    }
};
