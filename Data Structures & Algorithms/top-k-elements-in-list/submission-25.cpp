class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int it:nums){
            mp[it]++;
        }
        vector<vector<int>> freq(nums.size()+1);
        for(auto it:mp){
            freq[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i=freq.size()-1;i>=0;i--){
            for(int it:freq[i]){
            res.push_back(it);
            if(res.size()==k) return res;    
            }
        }
        return res;
    }
};
