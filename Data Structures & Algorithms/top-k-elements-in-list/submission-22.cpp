class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<vector<int>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
         vector<int> ans;
            
        for(int i=v.size()-1;i>(int)v.size()-k-1;i--){
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};
