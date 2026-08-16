class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(),l = 0,ans = INT_MAX;
        unordered_map<char,int>need, window;
        string res = "";

        for(int i=0;i<m;i++) 
            need[t[i]]++;
        
        int have = 0, uniq = need.size();
        for(int i=0;i<n;i++) {
            window[s[i]]++;
            if(need[s[i]] == window[s[i]]){
                have++;
            }   

            if(have == uniq) {
                while(l<=i && have == uniq) {
                    if(need[s[l]] != 0 && need[s[l]] == window[s[l]]) {
                        if((i-l+1) < ans) {
                            ans = (i-l+1);
                            res = s.substr(l,ans);
                        }
                        break;
                    }
                    window[s[l]]--;
                    l++;
                }
            }
        }
        return res;
    }
};
