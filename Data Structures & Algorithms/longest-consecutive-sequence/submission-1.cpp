class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int curr;
        int count=0;
        int larcount=0;
        for(int i=0;i<nums.size();i++){
            if(i==0) {curr=pq.top(); pq.pop(); count++;}
            if(curr==(pq.top()+1)) {count++; curr=pq.top(); pq.pop();}
            else if(curr==pq.top()) pq.pop();
            else {curr=pq.top(); pq.pop(); count=1;}
            if(count>larcount) larcount=count;
        }
        return larcount;
    }
};
