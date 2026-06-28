class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int _k;
    KthLargest(int k, vector<int>& nums) {
        for(int &it:nums){
            pq.push(it);
            if(pq.size()>k) pq.pop();
            
        }
        _k=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>_k) pq.pop();
        return pq.top();
    }
};
