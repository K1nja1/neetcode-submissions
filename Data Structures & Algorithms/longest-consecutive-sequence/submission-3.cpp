class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int curr = pq.top();
        pq.pop();

        int count = 1;
        int best = 1;

        while(!pq.empty()) {
            int x = pq.top();
            pq.pop();

            if(x == curr)
                continue;

            if(x == curr - 1)
                count++;
            else
                count = 1;

            curr = x;
            best = max(best, count);
        }

        return best;
    }
};