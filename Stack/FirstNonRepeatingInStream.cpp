string Solution::solve(string A) {
    queue<int> q;
    string s="";
    int * arr=new int[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
    for(int i=0;i<A.length();i++){
        q.push(A[i]);
        arr[A[i]-'a']++;
        if(arr[q.front()-'a']<2){
            s+=q.front();
        }else{
            while(!q.empty()&&arr[q.front()-'a']>=2){
                q.pop();
            }
            if(q.empty()){
                s+='#';
            }else{
                s+=q.front();
            }
        }
    }
    return s;
}
