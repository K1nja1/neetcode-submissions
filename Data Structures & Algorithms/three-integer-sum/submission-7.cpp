class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            if(i>0 &&(nums[i-1]==nums[i])) continue;
            while(j<k){
                int target=nums[i]+ nums[j]+nums[k];
                if(target==0) { 
                ans.push_back({nums[i],nums[j],nums[k]}); 
                j++; k--;
                while((j<k)&& (nums[j-1]==nums[j])) j++;
                while (j<k && nums[k+1]==nums[k]) k--;
                
                }
                if(target>0) k--;
                if(target<0) j++;
            }
        }
        return ans;
    }
};
