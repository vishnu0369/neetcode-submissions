class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums)
            q.push(i);
        while(q.size() > k)
            q.pop();
    }
    
    int add(int val) {  
        q.push(val);
        if(q.size() > k)
            q.pop();
        return q.top();
    }
};
