class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>m;
        vector<vector<string>>ans;
        for(auto i : strs) {
            int freq[26] = {0};
            for(auto c : i) {
                freq[c-'a']++;
            }

            string key = "";
            for(auto x : freq) {
                key += '#' + to_string(x);
            }

            m[key].push_back(i);
        }

        for(auto i : m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};