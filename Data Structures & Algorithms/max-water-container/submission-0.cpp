class Solution {
public:
    int maxArea(vector<int>& heights) {
        //using 2 pointers
        int left=0;
        int right =heights.size()-1;

int max_water=0;
        while(left<right){
            max_water=max(max_water,(right-left)*min(heights[left],heights[right]));
            if (heights[left]<heights[right]) left++;
            else{
                right--;
            }
        }
        return max_water;
    }
};
