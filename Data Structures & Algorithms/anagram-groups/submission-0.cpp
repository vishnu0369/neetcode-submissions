class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        vector<vector<string>>ans;
        for(auto i : strs) {
            string s = i;
            sort(s.begin(),s.end());
            m[s].push_back(i);
        }

        for(auto i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};