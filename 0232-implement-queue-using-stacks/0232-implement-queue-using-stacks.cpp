class MyQueue {
    stack<int>s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
       
        
    }
    
    int pop() {
       int n= s1.size();
       while(n!=0){
        s2.push(s1.top());
        s1.pop();
        n--;

       }
       int temp=s2.top();
       s2.pop();
       while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
       }
       return temp;
    }
    
    int peek() {
       int n= s1.size();
       while(n!=0){
        s2.push(s1.top());
        s1.pop();
        n--;

       }
       int temp=s2.top();
      
       while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
       }
       return temp;
    }
    
    bool empty() {
        return s1.empty();
    }
};

