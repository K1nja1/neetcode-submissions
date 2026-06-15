class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int ans=0;
        int area=0;
        while(left<right){
            if(left==right-1)  {area=1*min(heights[left],heights[right]);}
            else {area=(right-left)* min(heights[left],heights[right]);}
            if(ans<area) ans=area;
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return ans;
    }
};
