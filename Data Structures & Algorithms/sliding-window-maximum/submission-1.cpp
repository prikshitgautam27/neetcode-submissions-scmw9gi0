class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int>dq;
        vector<int> result;
// tracking the window range 
        for(int i=0;i<nums.size() ;i++){
            if(!dq.empty()  && dq.front()==i-k){
                dq.pop_front();
            }
// removing the ekement from the back 
while(!dq.empty() && nums[dq.back()]<nums[i]){
    dq.pop_back();
}
//  add element index to dq;
dq.push_back(i);

// push max which is dq.front as while loop removes all the min values  
if(i>= k-1){
    result.push_back(nums[dq.front()]);
}
        }
        return result;
    }
};
