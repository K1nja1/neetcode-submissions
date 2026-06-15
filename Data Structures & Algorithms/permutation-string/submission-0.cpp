class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0;
        int right=s1.size();
        unordered_map<char,int> st1;
        unordered_map<char,int> st2;
        for(int i=0;i<right;i++)    st1[s1[i]]++;
        for(int i=0;i<right;i++)    st2[s2[i]]++;
        if(st1==st2) return true;
        if(s1.size() > s2.size()) return false;
        while(right<s2.size()){
            
            st2[s2[left]]--;
            if(st2[s2[left]] == 0) st2.erase(s2[left]);
            left++;
            st2[s2[right]]++;
            right++;
            
            if(st1==st2) return true;
        }
        return false;
    }
};
