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
            // cout <<  "i->" << i << s[i] << " " << need[s[i]] << " " << window[s[i]] << endl;
            if(need[s[i]] == window[s[i]]){
                // cout << "n" << i << s[i] << endl;
                have++;
            }   

            if(have == uniq) {
                // cout << "enter" << i << endl;
                // ans = min(ans,(i-l+1));
                // res = s.substr(l,ans);
                while(l<=i && have == uniq) {
                    cout << s[l] << endl;
                    if(need[s[l]] != 0 && need[s[l]] == window[s[l]]) {
                        // cout << "*" << i << s[i] << need[s[l]] << endl;
                        // have--;
                        // window[s[l]]--;
                        // l++;
                        // cout << s[l] << window[s[l]] << endl;
                        if((i-l+1) < ans) {
                            ans = (i-l+1);
                            res = s.substr(l,ans);
                        }
                        
                        // cout << "break" << " " << res << endl;
                        break;
                    }
                    window[s[l]]--;
                    l++;
                    // ans = min(ans,(i-l+1));
                    // res = s.substr(l,ans);
                }
            }
        }
        return res;
    }
};
