class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prodpre(nums.size());
        vector<int> prodsuf(nums.size());
        prodpre[0]=1;
        prodsuf[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            prodpre[i]=prodpre[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            prodsuf[i]=prodsuf[i+1]*nums[i+1];
        }   
        vector<int> ans;         
        for(int i=0;i<nums.size();i++){
            ans.push_back(prodpre[i]*prodsuf[i]);
        }        
        return ans;
        
    }
};
