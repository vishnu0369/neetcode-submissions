class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<pair<int,int>> h(n);
        for(int i=0;i<n;i++) {
            if(i == 0){
                h[i].first = heights[i];
                h[n-i-1].second = heights[n-i-1];
            }else {
                h[i].first = max(h[i-1].first, heights[i]);
                h[n-i-1].second = max(h[n-i].second, heights[n-i-1]);
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++) {
            ans += min(h[i].first,h[i].second) - heights[i];
        }
        return ans;
    }
};
