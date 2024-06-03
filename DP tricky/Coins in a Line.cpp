int Solution::maxcoin(vector<int> &a) {
    int dp[501][501][2];
    int n = a.size();
    memset(dp,-1,sizeof(dp));
    auto DP = [&](int i,int j,int c,auto &&DP)->int{
        if(i > j) return 0;
        if(dp[i][j][c] != -1) return dp[i][j][c];
        int ans;
        if(c == 0){
            ans = max(DP(i+1,j,c^1,DP)+a[i],DP(i,j-1,c^1,DP)+a[j]);
        }
        else{
            ans = min(DP(i+1,j,c^1,DP)-a[i],DP(i,j-1,c^1,DP)-a[j]);
        }
        return dp[i][j][c] = ans;
    };
    int sum = 0; for(auto &x :a)sum += x;
    return ( sum+ DP(0,n-1,0,DP))/2;
}
