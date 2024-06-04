int Solution::wordBreak(string A, vector<string> &B) {
    sort(B.begin(),B.end());
    int n=A.size();
    multiset<string>b;
    for(auto &i:B)b.insert(i);
    int dp[6505];
    memset(dp,-1,sizeof(dp));
    auto DP = [&](int i,auto &&DP){
        if(i == n) return 1;
        if(dp[i]!=-1) return dp[i];
        int ok = 0;
        string s ="";
        for(int j=i;j<min(n,i+21);j++){
            s += A[j];
            if(b.find(s)!=b.end()){
                ok|=DP(j+1,DP);
            }
        }
        return dp[i]=ok;
    };
    return DP(0,DP);
}
