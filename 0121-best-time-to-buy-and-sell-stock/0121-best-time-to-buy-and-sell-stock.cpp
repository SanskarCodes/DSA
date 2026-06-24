class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        int min = prices[0];
        int maxprofit = 0;
        for(int i  = 0; i < n ; i++){
            if(prices[i]<min){
                min = prices[i];
            }
            else{
                maxprofit = max(maxprofit,prices[i] - min);
            }
        }
        if(maxprofit>0){
            return maxprofit;
        }
        return 0;        
    }
};