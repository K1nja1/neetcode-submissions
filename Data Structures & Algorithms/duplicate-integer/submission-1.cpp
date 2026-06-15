class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> num;
        for(int x=0;x<nums.size();x++){
            
            num.insert(nums[x]);
        }
        if(nums.size()==num.size()) return false;
        else return true;
    }
};