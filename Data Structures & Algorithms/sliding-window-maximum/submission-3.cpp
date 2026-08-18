class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int l = 0, n = nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++) {
            if(i+1 >= k) {
                while(!dq.empty() && dq.front() <= i-k) {
                    dq.pop_front();
                }
                while(!dq.empty() && nums[dq.front()] < nums[i]) {
                    dq.pop_front();
                }
                if(!dq.empty() && nums[dq.front()] <= nums[i]){
                    dq.push_front(i);
                }else{
                    while(!dq.empty() && nums[dq.back()] < nums[i])
                        dq.pop_back();
                    dq.push_back(i);
                }
                
                if(dq.empty())
                    dq.push_front(i);
                if(!dq.empty())
                    ans.push_back(nums[dq.front()]);
            }else {
                if(dq.empty()){
                    dq.push_back(i);
                }else if(nums[dq.front()] <= nums[i]){
                    while(!dq.empty() && nums[dq.front()] < nums[i]) {
                        dq.pop_front();
                    }
                    dq.push_front(i);
                }else {
                    while(!dq.empty() && nums[dq.back()] < nums[i])
                        dq.pop_back();
                    dq.push_back(i);
                }
            }

            // for(auto &i : dq)
            //     cout << i << "->" << nums[i] << ",";
            // cout << endl;
        }
        return ans;
    }
};
