class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto x:strs){
            res += to_string(x.size());
            res.push_back('#');
            for(char it:x) res.push_back(it);
           
        }
        return res;
    }

    vector<string> decode(string s) {

        vector<string> res;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find delimiter '#'
            while (s[j] != '#') {
                j++;
            }

            // Parse length
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract actual string
            res.push_back(s.substr(j, len));

            // Move to next encoded block
            i = j + len;
        }

        return res;
    }
};

