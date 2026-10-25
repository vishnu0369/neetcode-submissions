class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(auto &i: stones)
            pq.push(i);

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int d = abs(x-y);
            if(d)
                pq.push(d);
        }
        return pq.size() == 1 ? pq.top() : 0;
    }
};
