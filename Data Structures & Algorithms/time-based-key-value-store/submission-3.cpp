class TimeMap {
public:
    unordered_map<string,vector<pair <int,string> >> mp;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int left=0;
        vector<pair<int,string>> &pa=mp[key];
        
        int right=pa.size()-1;
        string ans="";
        while(left<=right){
            int mid=(left+right)/2;
            if (pa[mid].first==timestamp) ans=pa[mid].second;
            if(pa[mid].first<=timestamp){
                ans=pa[mid].second;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};
