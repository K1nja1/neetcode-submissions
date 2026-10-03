class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto &it:strs){
            res.append(to_string(it.size()));
            res.append("#");
            res=res+it;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            string l="";
            while(s[i]!='#'){
                l=l+s[i];
                i++;
            }
            int len=stoi(l);
            i++;
            string r="";
            r=r+s.substr(i,len);
            res.push_back(r);
            i=i+len;
        }
        return res;
    }
};
