vector<vector<int> > Solution::solve(int A, vector<vector<int> > &a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(A+1,0)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j][0] = a[i][j];
        }
    }
    for(int k = 1 ; k <= A ; k++){
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int ans = dp[i][j][k-1];
                if(i+1<n) ans = max(ans,dp[i+1][j][k-1]);
                if(i-1>=0) ans = max(ans,dp[i-1][j][k-1]);
                if(j+1<m) ans = max(ans,dp[i][j+1][k-1]);
                if(j-1>=0) ans = max(ans,dp[i][j-1][k-1]);
                dp[i][j][k] = ans;
            }
        }
    }
    vector<vector<int>>ans(n,vector<int>(m));
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            ans[i][j] = dp[i][j][A];
        }
    }
    return ans;
}
