class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        if(nums.size() == 0)
            return 0;
        int ans = 1, c = 1;

        for(int i=0;i<nums.size();i++) {
            if(s.find(nums[i]-1) != s.end()){
                continue;
            }else {
                int x = nums[i]+1;
                while(s.find(x) != s.end()){
                    x++;
                    c++;
                }
                ans = max(ans, c);
                c = 1;
            }
        }

        return ans;
    }
};
