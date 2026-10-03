class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int len=0;
        int maxlen=0;
        for(int x:st){
            if(!st.count(x-1)){
                len=1;
            
            while (st.count(x+len)) {
                len++;
            }
            maxlen=max(len,maxlen); 
        }
        }
        return maxlen;
    }
};
