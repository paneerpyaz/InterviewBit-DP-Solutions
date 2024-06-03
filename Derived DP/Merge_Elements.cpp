int Solution::solve(vector<int> &A) {
    int dp[201][201];
    memset(dp,-1,sizeof(dp));
    int n = A.size();
    auto DP = [&](int i,int j,auto &&DP)->int{
        if(j-i == 1){
            return A[i] + A[j];
        }
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        int s = 0;
        for(int k = i ; k <= j ; ++k) s += A[k];
        for(int mid = i ; mid <= j-1 ; ++mid){
            ans = min(ans, s + DP(i,mid,DP) + DP(mid+1,j,DP));
        }
        return dp[i][j] = ans;
    };
    return DP(0,n-1,DP);
}
