class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>>pq;

        for(int i=0;i<points.size();i++) {
            float x = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({x, i});
        }

        vector<vector<int>>ans;
        for(int i=0;i<k;i++) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
