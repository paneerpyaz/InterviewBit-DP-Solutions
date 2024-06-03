int Solution::solve(string A) {
    int n = A.size();
    int dp[1010][1010];
    memset(dp,-1,sizeof(dp));
    function<int(int,int)>DP = [&](int i,int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max({DP(i+1,j),DP(i,j-1),DP(i+1,j-1) + 2*(A[i] == A[j])});
    };
    return DP(0,n-1);
}
