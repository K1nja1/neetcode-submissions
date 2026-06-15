class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;

        while (left<right) {

            if (!(('A' <= s[right] && s[right] <= 'Z') || ('a' <= s[right] && s[right] <= 'z') ||('0' <= s[right] && s[right] <= '9'))) {
                right--;
                continue;
            }

            if (!(('A' <= s[left] && s[left] <= 'Z') || ('a' <= s[left] && s[left] <= 'z') ||('0' <= s[left] && s[left] <= '9'))) {
                left++;
                continue;
            }

            if ('a'<=s[left] && s[left]<='z') s[left]=s[left] - 32;

            if ('a' <= s[right] && s[right] <= 'z')s[right]=s[right] - 32;

            if (s[left] != s[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};