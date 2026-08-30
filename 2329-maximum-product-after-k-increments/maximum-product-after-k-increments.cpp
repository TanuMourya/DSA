class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : nums) {
            pq.push(x);
        }

        while(k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x + 1);
        }

        long long ans = 1;
        while(!pq.empty()) {
            ans = (ans * pq.top()) % 1000000007;
            pq.pop();
        }

        return ans;
    }
};