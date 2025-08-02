#include <stack>
class MyQueue {
public:
    stack<int> stack0; 
    stack<int> stack1;
    int top;

    MyQueue() {
    }
    
    void push(int x) {
       // std::cout << "I was at push last" << std::endl;
        if(stack0.empty()){
            top = x;
        }
        stack0.push(x);
    }
    
    int pop() { 
        int temp;
        int poppedValue;
        //std::cout << "I was at pop last" << std::endl;
        while(stack0.size() > 1){
             std::cout << "here 1" << std::endl;
            temp = stack0.top();
            stack0.pop();
            stack1.push(temp);
        }
        //std::cout << "My popped value is" << poppedValue << std::endl;
        poppedValue = stack0.top();
        stack0.pop();
        //std::cout << "Pop in 2"  << std::endl;
        if(!stack1.empty()){

            top = stack1.top(); // The top of the stack 1 is the front of the queue
        }
        //std::cout << "My top value is" << top << std::endl;
        while(!stack1.empty()){
        
           // std::cout << "here 2" << std::endl;
            temp = stack1.top();
            stack1.pop();
            stack0.push(temp);
        }
        return poppedValue;
    }
    
    int peek() {
       // std::cout << "I was at peek last" << std::endl;
        return top;
    }
    
    bool empty() {
        //std::cout << "I was at empty last" << std::endl;
       return stack0.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */