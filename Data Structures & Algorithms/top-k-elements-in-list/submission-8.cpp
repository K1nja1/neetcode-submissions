class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int,int> M;
            for(int i=0;i<nums.size();i++){
                M[nums[i]]++;
            }
            vector<vector<int>> v;
            for(auto x:M){

                v.push_back({x.second,x.first});
            }
            sort(v.begin(),v.end());
            vector<int> ans;
            for(int i=v.size()-1;i>(int)v.size()-k-1;i--){
                ans.push_back(v[i][1]);
            }
            return ans;
    }
};