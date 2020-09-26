#define M 1000000007
int Solution::maxSpecialProduct(vector<int> &A) {
    
    vector<long long> v1;
    stack<int> s1;
    for(int i=0;i<A.size();i++){
        if(s1.empty()){
            v1.push_back(0);
        }else if(A[i]<A[s1.top()]){
            v1.push_back(s1.top());
        }else{
            while(!s1.empty()&&A[i]>=A[s1.top()]){
                s1.pop();
            }
            if(s1.empty()){
                v1.push_back(0);
            }else{
                v1.push_back(s1.top());
            }
        }
        s1.push(i);
    }
    
    vector<long long> v2;
    stack<int> s2;
    for(int i=A.size()-1;i>=0;i--){
        if(s2.empty()){
            v2.push_back(0);
        }else if(A[i]<A[s2.top()]){
            v2.push_back(s2.top());
        }else{
            while(!s2.empty()&&A[i]>=A[s2.top()]){
                s2.pop();
            }
            if(s2.empty()){
                v2.push_back(0);
            }else{
                v2.push_back(s2.top());
            }
        }
        s2.push(i);
    }
    reverse(v2.begin(),v2.end());
    long long max=0;
    for(int i=0;i<v1.size();i++){
        v1[i]*=v2[i];
        if(v1[i]>max){
            max=v1[i];
        }
    }
    return max%M;
}
