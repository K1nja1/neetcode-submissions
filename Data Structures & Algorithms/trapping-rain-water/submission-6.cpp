class Solution {
public:
    int trap(vector<int>& height) {
        int left=1;
        int right=height.size()-2;
        int rMax=height[height.size()-1];
        int lMax=height[0];
        int ans=0;
        while(left<=right){            
            
            
            
            lMax=max(lMax,height[left]);
            rMax=max(rMax,height[right]);
            if(lMax<=rMax){ ans+=max(0,lMax - height[left]); left++;}
            else if(rMax<lMax) { ans+=max(0,rMax- height[right]);right--;}
            


        }
        return ans;
    }
};
