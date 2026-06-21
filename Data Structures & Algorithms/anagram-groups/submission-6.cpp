class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {

            int freq[26] = {0};

            for (char c : s)
                freq[c - 'a']++;

            string key;
            key.reserve(80);

            for (int x : freq)
                key += "#" + to_string(x);

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());

        for (auto& [_, group] : mp)
            ans.push_back(move(group));

        return ans;
    }
};