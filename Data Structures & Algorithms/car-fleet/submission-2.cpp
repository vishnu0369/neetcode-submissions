class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float>t(target+1);
        int n = position.size(), ans = 0;

        for(int i=0;i<n;i++) {
            float x = float((target-position[i]))/float(speed[i]);
            t[position[i]] = x;
        }
        float curr = 0;
        for(int i=target;i>=0;i--) {
            if(t[i] > curr) {
                ans++;
                curr = t[i];
            }
        }

        return ans;
    }
};
