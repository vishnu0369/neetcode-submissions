class Solution {
public:
    int maxArea(vector<int>& heights) {
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

        int l = 0, r = n-1, ans = 0;

        while(l < r) {
            ans = max(ans, (r-l)*min(h[l].first,h[r].second));

            if(h[l].first < h[r].second)
                l++;
            else 
                r--;
        }
        return ans;
    }
};
