class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>curres;
        backtrack(0, nums, target, res, curres);
        return res;
    }

    void backtrack(int start,vector<int>& nums, int target, vector<vector<int>>& res,vector<int>& curres  ){

       if(target == 0){
                res.push_back(curres);
                return;
            }

       
        for(int i= start ; i < nums.size() ; i++){
            if(nums[i] > target) break;
            curres.push_back(nums[i]);

            backtrack(i,nums ,target- nums[i] , res, curres);

            curres.pop_back();

             
        }


        
    }
};
