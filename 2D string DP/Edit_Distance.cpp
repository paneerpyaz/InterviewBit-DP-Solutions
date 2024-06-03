int Solution::minDistance(string A, string B) {
    int dp[451][451];
    int n = A.size();
    int m = B.size();
    memset(dp,-1,sizeof(dp));
    auto DP = [&](int i,int j,auto &&DP)->int{
        if(i == n) return m-j;
        if(j == m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = min({DP(i+1,j,DP)+1,DP(i,j+1,DP)+1,DP(i+1,j+1,DP) + (A[i] != B[j])});
    };
    return DP(0,0,DP);
}
