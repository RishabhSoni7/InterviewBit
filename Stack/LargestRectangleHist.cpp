vector<int> nslIndex(vector<int> A){
    stack<int> s;
    vector<int> v1;
    for(int i=0;i<A.size();i++){
        if(s.empty()){
            v1.push_back(-1);
        }else if(A[s.top()]<A[i]){
                v1.push_back(s.top());
        }else{
            while(!s.empty()&&A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()){
                v1.push_back(-1);
            }else{
                v1.push_back(s.top());
            }
        }
        s.push(i);
    }
    return v1;
}
vector<int> nsrIndex(vector<int> A){
    stack<int> s;
    vector<int> v1;
    for(int i=A.size()-1;i>=0;i--){
        if(s.empty()){
            v1.push_back(A.size());
        }else if(A[s.top()]<A[i]){
                v1.push_back(s.top());
        }else{
            while(!s.empty()&&A[s.top()]>=A[i]){
                s.pop();
            }
            if(s.empty()){
                v1.push_back(A.size());
            }else{
                v1.push_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(v1.begin(),v1.end());
    return v1;
}
int Solution::largestRectangleArea(vector<int> &A) {
    vector<int> nsl=nslIndex(A);
    vector<int> nsr=nsrIndex(A);
    int max=INT_MIN;
    for(int i=0;i<A.size();i++){
        int area=(nsr[i]-nsl[i]-1)*A[i];
        if(area>max){
            max=area;
        }
    }
    return max;
}
