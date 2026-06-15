class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
        int comp=target-nums[i];
            for(int j=nums.size()-1;i<j;j--){
                if(nums[j]==comp) return {i,j};
            }

        }   
             
    }
};
