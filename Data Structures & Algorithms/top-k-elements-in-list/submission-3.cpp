class Solution { 
    public: 
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        int mx = 0;
        unordered_map<int,int>m; 
        for(auto i : nums) {
            m[i]++; 
            mx = max(m[i], mx);
        }
        
        vector<vector<int>>arr(mx+1);

        for(auto i : m) {
            arr[i.second].push_back(i.first);
        }

        vector<int>ans;
        for(int i=mx;i>=0 && ans.size() != k;i--) {
            for(auto x : arr[i]) {
                ans.push_back(x);
            }
        }

        return ans;
    } 
};