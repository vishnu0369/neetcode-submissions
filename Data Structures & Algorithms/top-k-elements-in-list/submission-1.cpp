class Solution { 
    public: 
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        unordered_map<int,int>m; 
        for(auto i : nums) 
            m[i]++; 
        priority_queue<pair<int,int>>q; 
        for(auto i : m) { 
            q.push({i.second, i.first}); 
        } 
        vector<int>ans; 
        for(int i=0;i<k;i++) { 
            ans.push_back(q.top().second); 
            q.pop(); 
        } 
        return ans; 
    } 
};