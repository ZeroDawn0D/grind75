class MyQueue {
public:
    stack<int> usual_stack;
    stack<int> reverse_stack;
    MyQueue() {
        
    }
    
    void push(int x) { // push back
        usual_stack.push(x);
    }
    
    int pop() { //pop front
        if(reverse_stack.empty()){
            while(!usual_stack.empty()){
                reverse_stack.push(usual_stack.top());
                usual_stack.pop();
            }
        }
        
        int ans = reverse_stack.top();
        reverse_stack.pop();
        return ans;
    }
    
    int peek() {
        if(reverse_stack.empty()){
            while(!usual_stack.empty()){
                reverse_stack.push(usual_stack.top());
                usual_stack.pop();
            }
        }
        
        return reverse_stack.top();
    }
    
    bool empty() {
        return reverse_stack.empty() && usual_stack.empty();
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
