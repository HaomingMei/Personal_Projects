#include <deque>
class RecentCounter {
public:
    std::deque<int> mydequeue;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int counter = 1;
        if(mydequeue.empty()){
            mydequeue.push_back(t);
            return counter;
        }
        int last_req = mydequeue.back();
        int temp;
        while(mydequeue.front() != last_req){
            temp = mydequeue.front();
            if(temp >= t-3000){
                counter += 1;
                mydequeue.pop_front();
                mydequeue.push_back(temp);
            }
            else{
                mydequeue.pop_front();
            }
        }
        temp = mydequeue.front();
        if(temp >= t- 3000){
            counter += 1;
             mydequeue.pop_front();
            mydequeue.push_back(temp);
        }
        else{

            mydequeue.pop_front();  
        }

        mydequeue.push_back(t);
        return counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */