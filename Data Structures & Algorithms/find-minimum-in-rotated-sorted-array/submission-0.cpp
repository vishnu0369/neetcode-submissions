class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1,ans = INT_MAX;

        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] > nums[r])
                l = m + 1;
            else
                r = m - 1;

            ans = min(ans, nums[m]);
        }
        return ans;
    }
};