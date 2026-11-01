class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        rec(0, nums, ds, nums.size());
        return ans;
    }

    void rec(int idx, vector<int>& nums, vector<int> &ds, int n) {
        if(idx == n) {
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        rec(idx+1,nums,ds,n);
        ds.pop_back();
        rec(idx+1,nums,ds,n);
    }
};