class KthLargest {
int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        auto endPointer = nums.begin() + min(k, (int)nums.size());
        pq = priority_queue<int, vector<int>, greater<int>> (nums.begin(), endPointer); // Push less than or equal to first k ele in pq 
         for(int i = k; i < nums.size(); ++i) {
            pq.push(nums[i]);   //insert the rest
            pq.pop();           //Pop to maintain exactly less than or equal to k ele in pq
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();  //pq will hold atmost k+1 ele 
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */