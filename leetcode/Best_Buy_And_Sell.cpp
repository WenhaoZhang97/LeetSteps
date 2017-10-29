class Solution {
public:
    int max(int a,int b)
    {
        return (a>b?a:b);
    }
    int min(int a,int b){return (a<b?a:b);}
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int max_price=0,min_price=prices[0];
        for(int i=1;i<prices.size();i++) {
            min_price=min(min_price,prices[i-1]);
            max_price=max(max_price,prices[i]-min_price);
        }
        return max_price;
    }
};