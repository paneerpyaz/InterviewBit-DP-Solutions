int Solution::solve(vector<vector<int> > &a) {
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i-1][j-1];
        }
    }
    int ans = -1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a = i+1,b = j+1,A=n,B=m;
            int sum = dp[A][B]-dp[a-1][B]-dp[A][b-1]+dp[a-1][b-1];
            ans=max(ans,sum);
        }
    }
    return ans;
}
