class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxprofit =INT_MIN;
        int min_price =INT_MAX;
for(int i=0;i<prices.size();i++){
    min_price=min(min_price,prices[i]);
    maxprofit=max(maxprofit,prices[i]-min_price);
}
return maxprofit;
    }
};
