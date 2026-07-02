class Solution {
public:

    string encode(vector<string>& strs) {
        string x = "";
        for(auto i : strs) {
            x+=to_string(i.size()) + '#' + i;
        }

        cout << x << endl;
        return x;
    }

    vector<string> decode(string s) {
        vector<string>ans; 
        string x = "", n = "";
        int c = 0;
        for(int i=0;i<s.size();) {
            if(c == 0) {
                while(s[i] != '#') {
                    n += s[i];
                    i++;
                }
                i++;
                c = stoi(n);
                if(c == 0){
                    ans.push_back("");
                }
                n="";
            }else {
                while(c) {
                   x += s[i];
                   i++, c--; 
                }
                ans.push_back(x);
                x="";
            }
        }
    
        return ans;
    }
};
