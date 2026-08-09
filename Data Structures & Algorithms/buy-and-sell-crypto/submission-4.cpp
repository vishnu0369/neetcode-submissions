class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, ll = prices[0];
        for(auto &i : prices) {
            ans = max(ans, i - ll);
            ll = min(ll, i);
        }
        return ans;

    }
};
