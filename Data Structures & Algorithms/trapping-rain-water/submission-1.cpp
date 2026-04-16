class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,leftmax=0,rightmax=0,t_w=0;//t_w is total_water

        while(left<=right){
            if(height[left]<height[right]){
                if(height[left]>=leftmax){
                    leftmax=height[left];
                }
                else{
                    t_w+= leftmax-height[left];
                }
                left++;
            }


            else{
                if(height[right]>rightmax){
                    rightmax=height[right];
                }
                else{
                    t_w+=rightmax-height[right];
                }
                right--;
            }


        }
return t_w;
    }
};

