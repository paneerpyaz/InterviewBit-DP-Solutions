int Solution::solve(int A) {
    int64_t dp[A+1][2] = {};
    dp[1][0] = 24;
    dp[1][1] = 12;
    int m = 1e9+7;
    for(int i = 2 ; i <= A ; i++){
        dp[i][0] = ((11*dp[i-1][0])%m + (10*dp[i-1][1])%m)%m;
        dp[i][1] = ((7*dp[i-1][1])%m + (5*dp[i-1][0])%m)%m; 
    }
    return (dp[A][0]%m + dp[A][1]%m)%m;
}
