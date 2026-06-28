class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<points.size();i++){
            pq.push({ sqrt( (points[i][0]*points[i][0])+(points[i][1]*points[i][1])), i});
        }
        while(pq.size()>k) pq.pop();
        vector<vector<int>> res;
        int n=pq.size();
        for(int i=0;i<n;i++){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
