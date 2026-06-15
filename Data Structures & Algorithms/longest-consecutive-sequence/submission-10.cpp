class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        int curr;
        int count=0;
        int larcount=0;
        for(int i=0;i<n;i++){
            if(i==0) {curr=pq.top(); pq.pop(); count++;}
            if(curr==(pq.top()+1)) {count++; curr=pq.top(); pq.pop();}
            else if(curr==pq.top()) pq.pop();
            else {curr=pq.top(); pq.pop(); count=1;}
            larcount=max(count,larcount);
        }
        return larcount;
    }
};
