int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int dp[n+1][3] = {};
    dp[0][0] = min(A[0][1],A[0][2]);
    dp[0][1] = min(A[0][2],A[0][0]);
    dp[0][2] = min(A[0][1],A[0][0]);
    for(int i = 1 ; i < n ; i++){
        dp[i][0] = min(dp[i-1][1] + A[i][1],dp[i-1][2] + A[i][2]);
        dp[i][1] = min(dp[i-1][0] + A[i][0],dp[i-1][2] + A[i][2]);
        dp[i][2] = min(dp[i-1][0] + A[i][0],dp[i-1][1] + A[i][1]);
    }
    return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}
