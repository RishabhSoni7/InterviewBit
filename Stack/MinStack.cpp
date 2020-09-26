 
    stack<int> s;
    stack<int> s1;
MinStack::MinStack() {
    while(!s.empty()){
        s.pop();
    }
    while(!s1.empty()){
        s1.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    if(s1.empty()||s1.top()>=x){
        s1.push(x);
    }
}

void MinStack::pop() {
    if(s.empty()){
        return;
    }
    int ans=s.top();
    s.pop();
    if(ans==s1.top()){
        s1.pop();
    }
}

int MinStack::top() {
    if(s.empty()){
        return -1;
    }
    return s.top();
}

int MinStack::getMin() {
    if(s1.empty()){
        return -1;
    }
    return s1.top();
}

