class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>p = nums, s = nums, ans(n,0);

        for(int i=1;i<n;i++) {
            p[i] = p[i] * p[i-1];
            s[n-i-1] = s[n-i-1] * s[n-i];
        }

        for(int i=0;i<n;i++) {
            if(i == 0)
                ans[i] = s[i+1];
            else if(i == n-1)
                ans[i] = p[i-1];
            else
                ans[i] = p[i-1] * s[i+1];
        }
        return ans;
    }
};
