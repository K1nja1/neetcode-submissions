class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preprod(nums.size());

        preprod[0]=1;
        preprod[nums.size()-1]=1;
        
        for(int i=1;i<nums.size();i++){
            preprod[i]=nums[i-1]*preprod[i-1];
        }
        int product=1;
        for(int i=nums.size()-1;i>=0;i--){
            preprod[i]*= product;
            product*= nums[i];
        }
        return preprod;
    }
};
