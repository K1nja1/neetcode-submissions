class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int n=strs.size();
            unordered_map<string,vector<string>> mp;
            vector<string> str=strs;
            for(int i=0;i<n;i++){
                sort(str[i].begin(),str[i].end());
                mp[str[i]].push_back(strs[i]);
            }
            vector<vector<string>> res;
            
            for(auto it:mp){
                
                    res.push_back(it.second);
            }
            return res;
            
        

            
    }
};
