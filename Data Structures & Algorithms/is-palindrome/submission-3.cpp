class Solution {
public:
    bool isPalindrome(string s) {
        string f = "";
        for(auto &i : s) {
            if((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
                f += tolower(i);
            }
        }

        int l = 0, r = f.size() - 1;
        while(l < r) {
            if(f[l] != f[r])
                return false;
            else {
                l++, r--;
            }
        }
        return true;
    }
};
