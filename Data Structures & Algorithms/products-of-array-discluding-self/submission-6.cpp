class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> prodpre(size);
        vector<int> prodsuf(size);
        prodpre[0]=1;
        prodsuf[size-1]=1;
        for(int i=1;i<size;i++){
            prodpre[i]=prodpre[i-1]*nums[i-1];
        }
        for(int i=size-2;i>=0;i--){
            prodsuf[i]=prodsuf[i+1]*nums[i+1];
        }   
        vector<int> ans(size);         
        for(int i=0;i<size;i++){
            ans[i]=prodpre[i]*prodsuf[i];
        }        
        return ans;
        
    }
};
