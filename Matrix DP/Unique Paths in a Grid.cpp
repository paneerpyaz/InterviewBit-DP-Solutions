int Solution::uniquePathsWithObstacles(vector<vector<int> > &a) {
    int n = a.size();
    int m = a[0].size();
    if(a[n-1][m-1]) return 0;
    vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int dx[4] = {1,0};
    int dy[4] = {0,1};
    auto dfs = [&](int i,int j,auto &&dfs)->int{
        if(i==n-1 && j==m-1) return 1;
        if(i<0||j<0||i>=n||j>=m||a[i][j]==1) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int ans = 0;
        for(int k=0;k<2;k++){
            int ii = i+dx[k];
            int jj = j+dy[k];
            ans += dfs(ii,jj,dfs);
        }
        return dp[i][j] = ans;
    };
    return dfs(0,0,dfs);
}
