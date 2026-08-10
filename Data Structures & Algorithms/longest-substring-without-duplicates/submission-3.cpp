class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>m;
        int n = s.size(), l = 0, ans = 0;
        for(int i=0;i<n;i++) {
            if(m.find(s[i]) == m.end()) {
            }else{
                if(l <= m[s[i]])
                    l = m[s[i]]+1;
            }
            ans = max(ans, (i-l+1));
            m[s[i]] = i;
        }
        return ans;
    }
};