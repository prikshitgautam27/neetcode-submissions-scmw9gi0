class Solution {
public:
    int findDuplicate(vector<int>& nums) {// floyd cycle detection not use extra space 
        // using tortoise and hare algo
   int slow=nums[0];
        int fast = nums[0];

// finding the meet point like slow=2,fast=2

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
            
        }while(slow!=fast);

// finding the duplicate
        fast=nums[0];
         while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
         }





        return slow;
    }
};
