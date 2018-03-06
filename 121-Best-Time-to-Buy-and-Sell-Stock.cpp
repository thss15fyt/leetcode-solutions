class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<int> profit(n, 0);
        profit[n - 1] = -prices[n - 1];
        int max_price = prices[n - 1];
        int max_profit = 0;
        for(int i = n - 2; i >= 0; --i) {
            profit[i] = max_price - prices[i];
            max_price = (prices[i] > max_price) ? prices[i] : max_price;
            max_profit = (profit[i] > max_profit) ? profit[i] : max_profit;
        }    
        return max_profit;
    }
};