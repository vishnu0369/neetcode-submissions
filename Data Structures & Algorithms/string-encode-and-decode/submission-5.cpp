class Solution {
public:
    string encode(vector<string>& strs) {
        string x = "";
        for(auto i : strs) {
            x+=to_string(i.size()) + '#' + i;
        }

        return x;
    }

    vector<string> decode(string s) {
        vector<string>ans; 
        int i = 0;
        while(i < s.size()) {
            int n = 0;
            while(s[i] != '#') {
                n = n*10 + (s[i] - '0');
                i++;
            }
            i++;
            ans.push_back(s.substr(i,n));
            i+=n;
            n = 0;
        }
    
        return ans;
    }
};
