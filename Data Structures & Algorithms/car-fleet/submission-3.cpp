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
        sort(position.begin(),position.end());
        for(int i=n-1;i>=0;i--) {
            if(t[position[i]] > curr) {
                ans++;
                curr = t[position[i]];
            }
        }

        return ans;
    }
};
