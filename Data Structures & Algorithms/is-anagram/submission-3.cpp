class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sv(26,0);
        vector<int> tv(26,0);
        if(s.size()!=t.size()) return false;
        for(char it:s){
            sv[it-'a']++;
        }
        for(char it:t){
            tv[it-'a']++;
        }
        if(tv==sv) return true;
        else return false;

    }
};
