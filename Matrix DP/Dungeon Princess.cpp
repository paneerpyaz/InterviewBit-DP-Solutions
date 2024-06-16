int Solution::calculateMinimumHP(vector<vector<int> > &a) {
    int n=a.size();
    int m=a[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[n-1][m-1]=a[n-1][m-1]>0 ? 1 : abs(a[n-1][m-1])+1;
    for(int i=n-2 ;i>=0;i--){
        dp[i][m-1]=max(dp[i+1][m-1]-a[i][m-1],1);
    }
    for(int i=m-2;i>=0;i--){
        dp[n-1][i]=max(dp[n-1][i+1]-a[n-1][i],1);
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-a[i][j],1);
        }
    }
    return dp[0][0];
}
