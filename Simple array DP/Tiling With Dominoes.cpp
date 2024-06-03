int Solution::solve(int A) {
    int M = 1e9+7;
    int dp[A+1][3] = {};
    dp[1][1] = 1;
    dp[1][2] = 1;
    if(A > 1) dp[2][0] = 3;
    for(int i = 3 ; i <= A ; i++){
        dp[i][1] = (dp[i-1][0]%M + dp[i-2][1]%M)%M;
        dp[i][2] = (dp[i-1][0]%M + dp[i-2][2]%M)%M;
        dp[i][0] = (dp[i-1][1]%M + dp[i-1][2]%M + dp[i-2][0]%M)%M;
    }
    return dp[A][0];
}
