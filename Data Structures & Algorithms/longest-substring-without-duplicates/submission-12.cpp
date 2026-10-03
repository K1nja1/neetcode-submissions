class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_set<char> st;
        int left=0;
        int res=0;

        for(int right=0;right<s.size();right++){
            while(st.count(s[right])) {st.erase(s[left]); left++;}
            st.insert(s[right]);
            res=max(res,right-left+1);
        }
        return res;
    }
};
