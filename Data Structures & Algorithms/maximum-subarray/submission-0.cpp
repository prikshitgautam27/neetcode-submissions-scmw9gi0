class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far= nums[0];
        int currsum=nums[0];

        for(int i=1;i <nums.size() ; i++){
                currsum=max(nums[i]+ currsum,nums[i] );
                max_so_far= max(currsum, max_so_far);
        }
        return max_so_far;
    }
};
