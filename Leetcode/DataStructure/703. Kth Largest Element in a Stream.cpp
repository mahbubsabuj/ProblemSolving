class KthLargest {
public:
    priority_queue<int> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(-n);
        }
        K = k;
        while (pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(-val);
        if (pq.size() > K) pq.pop();
        return pq.top() * -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */