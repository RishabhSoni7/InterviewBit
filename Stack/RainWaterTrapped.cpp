vector<int> largestTillNowInLeft(vector<int> A){
    vector<int> v;
    int maxTillNow=A[0];
    v.push_back(maxTillNow);
    for(int i=1;i<A.size();i++){
        if(A[i]>maxTillNow){
            maxTillNow=A[i];
        }
        v.push_back(maxTillNow);
    }
    return v;
}

vector<int> largestTillNowInRight(vector<int> A){
    vector<int> v;
    int maxTillNow=A[A.size()-1];
    v.push_back(maxTillNow);
    for(int i=A.size()-2;i>=0;i--){
        if(A[i]>maxTillNow){
            maxTillNow=A[i];
        }
        v.push_back(maxTillNow);
    }
    reverse(v.begin(),v.end());
    return v;
}

int Solution::trap(const vector<int> &A) {
    vector<int> lMax=largestTillNowInLeft(A);
    vector<int> rMax=largestTillNowInRight(A);
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans+=(min(lMax,rMax)-A[i]);
    }
    return ans;
    
}
