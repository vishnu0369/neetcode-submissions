class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int x = -1* nums[i];

            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[l] + nums[r];

                if(sum > x) 
                    r--;
                else if(sum < x)
                    l++;
                else {
                    ans.push_back({nums[l], nums[r], nums[i]});
                    if(l < n){
                        while(l < r && nums[l] == nums[l+1])
                            l++;
                    }
                    if(r > l) {
                        while(r > l && nums[r] == nums[r-1])
                            r--;
                    }
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};
