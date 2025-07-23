#include <queue>
class RecentCounter {
public:
    std::queue<int> myqueue;
    RecentCounter() {
        lastReqCount = 0;
    }
    
    int ping(int t) {
        if(myqueue.empty()){
            lastReqCount += 1;
            myqueue.push(t);
            return lastReqCount;
        }
        int last_req = myqueue.back();
        if(last_req < t- 3000){
            while(!myqueue.empty()){
                myqueue.pop();
            }
            lastReqCount = 1;
            myqueue.push(t);
            return lastReqCount;
        }
        int temp;
        // Goal: Remove what is not within the t- 3000 to t
        while(!myqueue.empty()){
            temp = myqueue.front();
            if(temp >= t-3000){
                lastReqCount +=1;
                myqueue.push(t);
                return lastReqCount;
            }
            else{
                lastReqCount -= 1;
                myqueue.pop();
            }
        }
        myqueue.push(t);
        lastReqCount +=1;
        return lastReqCount;


    }
private:

    int lastReqCount;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */