class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int right=piles[n-1];
        int left=1;
        int k=right;
        
        while(left<=right){
            int mid=left+(right-left)/2;
            int sumdiv=0;
            for(int i=0;i<piles.size();i++){
                sumdiv+=(piles[i]+mid-1)/mid;

            }
            if(sumdiv>h){
                left=mid+1;
            }
            else {k=min(k,mid);
                right=mid-1;}
                    
        
        }
            
        return k;



    }
};
