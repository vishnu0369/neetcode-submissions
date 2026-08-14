class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>m;
        int x = k, l = 0, ans = 0, mx = 0, n = s.size();
        char c = s[0];
        for(int i=0;i<n;i++) {
            m[s[i]]++;
            mx=max(mx, m[s[i]]);
            if((i-l+1) - mx > k) {
                while((i-l+1)-mx > k) {
                    m[s[l]]--;
                    l++;
                }
                c = s[i];
            }
            ans = max(ans, (i-l+1));
        }
        return ans;
    }
};