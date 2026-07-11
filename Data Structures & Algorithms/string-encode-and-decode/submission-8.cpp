class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto x:strs){
            for (auto it:x) res.push_back(it);
            res.push_back('~');
            
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res(1);
        int i=0;
        for(auto x:s){

            if (x=='~') { i++; res.push_back(""); continue;}
            res[i].push_back(x);
        }
        res.pop_back();
        return res;
    }
};
