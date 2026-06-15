class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mini = nums[0];
        while (left <=right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                mini = min(mini,nums[mid]);
                right = mid-1;
            }
            else  if(nums[right]<nums[left]){
                mini = min(mini,nums[mid]);
                left = mid + 1;
            }
            else {
                mini=min(mini,nums[left]);
                return mini;}
            
        }

        return mini;
    }
};
