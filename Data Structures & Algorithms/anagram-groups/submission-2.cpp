class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        vector<vector<string>>ans;
        for(auto i : strs) {
            string x = "000000000000000000000000000";
            for(auto j : i) {
                x[j-'a']++;
            }
            m[x].push_back(i);
        }

        for(auto i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};