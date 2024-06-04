int Solution::numDecodings(string A) {
    int n = A.size();
    int m = 1e9+7;
    int dp[100001];
    memset(dp,-1,sizeof(dp));
    if(A[0]=='0') return 0;
     auto DP =[&](int i,auto &&DP)->int{
        if(i == n) return 1LL;
        if(i > n) return 0LL;
        if(A[i] == '0') return 0LL;
        if(dp[i] != -1) return dp[i];
        //choose A[i]
        int ans = DP(i+1,DP)%m;
        //choose A[i] and A[i+1]
        if(i+1<n && 10*(A[i]-'0')+A[i+1]-'0' <= 26){
          // cout<<10*(A[i]-'0')+A[i+1]-'0'<<'\n';
          ans += DP(i+2,DP);
        }
        ans %= m;
        return dp[i] = ans;
    };
    return DP(0,DP);
}
