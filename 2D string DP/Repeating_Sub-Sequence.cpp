int Solution::anytwo(string A) {
    int n = A.size();
    int dp[101][101];
    memset(dp,-1,sizeof(dp));
    auto DP =[&](int i,int j,auto &&DP){
        if(i >= n || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = max({DP(i+1,j+1,DP) + (A[i] == A[j]),DP(i,j+1,DP)});
        if(i+2 < j ) ans = max(ans, DP(i+2,j,DP));
        return dp[i][j] = ans;
    };
    return (DP(0,1,DP) >= 2);
}
