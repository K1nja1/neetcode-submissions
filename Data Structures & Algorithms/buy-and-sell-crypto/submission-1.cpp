class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int right=1;
        int left=0;
        int ans=0;
        while(right<prices.size()){
            if(prices[right]>prices[left]) {ans=max(ans,prices[right]-prices[left]); right++;}
            else{
                left=right;
                right++;
            }
        }
        return ans;
    }
};
