class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int>q;

        vector<int>freq(26,0);
        for(auto i : tasks) {
            freq[i-'A']++;
        }

        for(auto i : freq) {
            if(i != 0)
                q.push(i);
        }

        while(!q.empty()) {
            vector<int>v;

            int c = n+1;
            while(c && !q.empty()) {
                int top = q.top();
                q.pop();
                if(top > 1){
                    v.push_back(top-1);
                }
                time++;
                c--;
            }

            for(auto i : v)
                q.push(i);

            if(q.empty())
                break;
            time += c;
        }
        return time;
    }
};