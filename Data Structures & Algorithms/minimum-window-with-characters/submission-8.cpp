class Solution {
public:
    string minWindow(string s, string t) {
        int left=0;
        int right=0;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<t.size();i++) mp2[t[i]]++;
        int start=0;
        int have=0;
        int len=9999999;
        while(right<s.size()){
            
            mp1[s[right]]++;
            if( mp2.count(s[right]) && (mp1[s[right]]==mp2[s[right]])) have++;            
            while(have==mp2.size()){                
                if(right-left+1<len) {len=right-left+1; start=left;}
                mp1[s[left]]--;
                if(mp2.count(s[left]) && mp1[s[left]]<mp2[s[left]]) {have--;}
                left++;
        }
        right++;                         
        }
        return len == 9999999?"":s.substr(start,len);
        

    }
    
};
