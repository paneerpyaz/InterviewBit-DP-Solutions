int Solution::solve(string A, string B) {
    int n = A.size();
    int m = B.size();
    int dp[1010][1010];
    memset(dp,-1,sizeof(dp));
    auto DP = [&](int i,int j,auto &&DP){
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max({DP(i+1,j,DP),DP(i,j+1,DP),DP(i+1,j+1,DP) + (A[i] == B[j])});
    };
    return DP(0,0,DP);
}
