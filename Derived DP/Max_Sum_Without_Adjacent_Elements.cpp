int Solution::adjacent(vector<vector<int>> &A) {
    int n = A[0].size();
    vector<int>a(n);
    for(int i = 0 ; i < n ; ++i){
        a[i] = max(A[0][i],A[1][i]);
    }
    if(n == 1) return a[0];
    vector<int>dp(n,0);
    dp[0] = a[0];
    dp[1] = max(a[0],a[1]);
    for(int i = 2 ; i < n ; ++i){
        dp[i] = max(dp[i],dp[i-2] + a[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    return dp[n-1];
}
