class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int left=0;
        int right=n-1;
// if first element is not rotated
        if(nums[left]<= nums[right]){
            return nums[left];
        }
        while(left< right){
            int mid= left+ (right - left)/2;

            if(nums[right]<nums[mid]){
             left=mid+1;
            }

            else{
               right =  mid;

            }
        }
return nums[left];
    }
};
