class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        rec(0, nums, target, ds, 0);
        for(auto &i :s)
            ans.push_back(i);
        return ans;
    }

    void rec(int idx, vector<int>& nums, int t, vector<int>& ds, int sum) {
        if(sum > t)
            return;

        if(sum == t){
            s.insert(ds);
            return;
        }
        
        if(idx == nums.size()) 
            return;

        for(int i=idx;i<nums.size();i++) {
            ds.push_back(nums[idx]);
            sum+=nums[idx];
            rec(i, nums, t, ds, sum);
            ds.pop_back();
            sum-=nums[idx];
        }
        rec(idx+1, nums, t, ds, sum);
    }
};