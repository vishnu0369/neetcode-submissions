class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m1[26] = {0}, m2[26] = {0}, n = s2.size(), m = s1.size();
        if(n < m)   return false;
        for(auto &i : s1)
            m1[i-'a']++;
        
        int l = 0;
        for(int i=0;i<n;i++) {
            if(l == 0) {
                m2[s2[i]-'a']++;
                if(i-l+1 == m) {
                    bool f = true;
                    for(int j=0;j<26;j++) {
                        if(m1[j] != m2[j]){
                            f=false;
                            break;
                        }
                    }
                    if(f)   return true;
                    m2[s2[l]-'a']--;
                    l++;
                }
            }else {
                m2[s2[i]-'a']++;
                bool f = true;
                for(int j=0;j<26;j++) {
                    if(m1[j] != m2[j]){
                        f=false;
                        break;
                    }
                }
                if(f)   return true;
                m2[s2[l]-'a']--;
                l++;
            }
        }
        
        return false;
    }
    
};
