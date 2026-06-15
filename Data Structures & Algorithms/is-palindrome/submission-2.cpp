class Solution {
public:
    bool isAlphanum(char c){
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
            int i=0;
            int j=s.size()-1;
            while(i<j){
                if(!isAlphanum(s[i])) {i++; continue;}
                if(!isAlphanum(s[j])) {j--; continue;}
                if( tolower(s[i]) != tolower(s[j]) ) return false;   
                i++;
                j--;
            }
            return true;
    }

};
