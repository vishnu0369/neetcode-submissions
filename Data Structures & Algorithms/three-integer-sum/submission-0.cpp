class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++) {
            int x = -1* nums[i];

            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[l] + nums[r];

                if(sum > x) 
                    r--;
                else if(sum < x)
                    l++;
                else {
                    ans.insert({nums[l], nums[r], nums[i]});
                    l++;
                }
            }
        }

        vector<vector<int>>res;
        for(auto &i : ans)
            res.push_back(i);
        return res;
    }
};
