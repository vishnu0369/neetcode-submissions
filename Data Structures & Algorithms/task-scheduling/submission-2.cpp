class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int>pq;

        int freq[26] = {0};
        for(auto &i: tasks) 
            freq[i - 'A']++;
        
        for(auto &i: freq)
            if(i != 0)
                pq.push(i);

        while(!pq.empty()) {
            vector<int>temp;
            int c = n+1;
            while(c && !pq.empty()) {
                int top = pq.top();
                pq.pop();

                if(top-1 > 0)
                    temp.push_back(top-1);
                c--;
                time++;
            }
            for(auto &i: temp)  
                pq.push(i);

            if(pq.empty())
                break;
                
            time += c;
        }
        return time;
    }
};