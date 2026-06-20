class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int m[26] = {0};
        for(auto i : s) 
            m[i-'a']++;

        for(auto i : t) {
            if(--m[i-'a'] < 0)
                return false;
        }
        return true;
    }
};
