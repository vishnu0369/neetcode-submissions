class Solution {
public:
    bool isValid(vector<int>& piles, int h, int k) {
        int sum = 0;
        for(auto &i : piles) {
            sum += (i+k-1)/k;
        }
        return sum <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while(l <= r) {
            int m = l + (r - l)/2;

            if(isValid(piles, h, m))
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
