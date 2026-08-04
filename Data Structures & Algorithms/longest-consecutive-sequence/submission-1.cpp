class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        if(nums.size() == 0)
            return 0;
        int ans = 1, c = 1;

        for(auto &i : s) {
            if(s.find(i+1) != s.end()) {
                c++;
                ans = max(ans, c);
            }else {
                c = 1;
            }
        }

        return ans;
    }
};
