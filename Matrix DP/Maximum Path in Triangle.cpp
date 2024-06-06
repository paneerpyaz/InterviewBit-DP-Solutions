int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1e9));
    dp[0][0] = a[0][0];
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i+1 ; j++){
            if(j<i) dp[i][j] = dp[i-1][j]+a[i][j];
            if(j>=1) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i][j]);
        }
    }
    int ans = -1e9;
    for(int j = 0 ; j < n ; j++){
        ans = max(ans,dp[n-1][j]);
    }
    return ans;
}
