class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto &it:strs){
            vector<int> freq(26,0);
            for(char &c:it){
                freq[c-'a']++;
            }
        
            string fre="";
            for(int i=0;i<26;i++){
                fre+='#'+freq[i];
            }
            mp[fre].push_back(it);

        }
        vector<vector<string>> ans;
        for(auto it:mp){
                ans.push_back(it.second);
        }
        return ans;
    }
};
