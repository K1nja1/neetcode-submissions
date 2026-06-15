class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int curr=(right+left)/2;
            if(nums[curr]==target) return curr;
            if(nums[curr]<target) left=curr+1;
            if(nums[curr]>target) right=curr-1;
        }
        return -1;
        
    }
};
