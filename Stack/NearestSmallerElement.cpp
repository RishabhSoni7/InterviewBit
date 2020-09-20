vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> v1;
    stack<int> s;
    for(int i=0;i<A.size();i++){
        if(s.empty()){
            v1.push_back(-1);
        }else if(s.top()<A.at(i)){
            v1.push_back(s.top());
        }else{
            while(!s.empty()&&s.top()>=A.at(i)){
                s.pop();
            }
            if(s.empty()){
                v1.push_back(-1);
            }else{
                v1.push_back(s.top());
            }
        }
        s.push(A.at(i));
    }
    return v1;
}
