class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int index1 = prices.size() - 1;
        int index2 = discounts.size() - 1;

        double ans = 0;

        while (index1 >= 0) {
            if (index2 >= 0) {
                ans += prices[index1] * (double)(100 - discounts[index2]) / 100;
                index2--;
            } else {
                ans += prices[index1];
            }

            index1--;
        }

        return ans;
    }
};