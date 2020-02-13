class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        
        if(prices.size()>0) {
            int profit[prices.size()], list[prices.size()];

            profit[0]=0;
            list[0]=prices[0];

            for(int i=1; i<prices.size(); i++) {
                if(list[i-1]<prices[i]) {
                    profit[i]=prices[i]-list[i-1];
                    list[i]=list[i-1];
                } else {
                    profit[i]=0;
                    list[i]=prices[i];
                }

                max_profit=max(max_profit,profit[i]);
            }
        }
        
        return max_profit;
    }
};

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
