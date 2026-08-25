class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), ans = 0;
        vector<pair<int,float>>t(n);

        for(int i=0;i<n;i++) {
            float x = float((target-position[i]))/float(speed[i]);
            t[i] = {position[i],x};
        }
        float curr = 0;
        sort(t.begin(),t.end());
        for(int i=n-1;i>=0;i--) {
            if(t[i].second > curr) {
                ans++;
                curr = t[i].second;
            }
        }

        return ans;
    }
};
