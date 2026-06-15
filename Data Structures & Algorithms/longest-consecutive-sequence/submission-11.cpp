class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> st;
       for(int x:nums){
        st.insert(x);
       }
       int maxcount=0;
       for(auto it:st){
            int curr=it;
            int count=1;
            
            while(st.count(curr+1)){
                curr++;
                count++;
            }
            maxcount=max(count,maxcount);
       }
       return maxcount;
    }
    
};
