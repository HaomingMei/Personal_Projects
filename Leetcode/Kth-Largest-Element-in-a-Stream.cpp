#include <queue>
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; //min heap to keep track of the 0th to k-1th largest
    int kth;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(auto ele : nums) {
            pq.push(ele);
    
        }
        while(pq.size() > k){
                pq.pop();
        } 
    }
  
  
    int add(int val) {
        pq.push(val);
       // Pop if there is more than k elements on the min heap
        if(pq.size() > kth){
            pq.pop();
        } 
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */