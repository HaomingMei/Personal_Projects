#include <deque>        
class MyStack {
public:
    std::deque<int>mydequeue;
    MyStack() {
        
    }
    
    void push(int x) {
        mydequeue.push_front(x);
    }
    
    int pop() {
        int front = mydequeue.front();
        mydequeue.pop_front();
        return front;
        
    }
    
    int top() {
        return mydequeue.front();
        
    }
    
    bool empty() {
        return mydequeue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */