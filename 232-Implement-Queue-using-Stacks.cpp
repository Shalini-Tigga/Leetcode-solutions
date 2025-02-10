class MyQueue {
public:
    //amortized
    stack<int> a ; 
    stack<int> b;
    MyQueue() { 
    }
    
    void push(int x) {
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        a.push(x);
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
    }
    int pop() {
        int k = a.top();
        a.pop();
        return k;
    }
    
    int peek() {
        return a.top();
    }
    
    bool empty() {
        return a.empty();
    }
};
