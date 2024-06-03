int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int dp[1001][10001];
    memset(dp,-1,sizeof(dp));
    auto DP = [&](int index,int prev,auto &&DP)->int{
        if(index == n){
            return 0;
        }
        if(dp[index][prev] != -1) return dp[index][prev];
        int ans = DP(index+1,prev,DP);
        if(A[index][0] > prev){
            ans = max(ans, DP(index+1,A[index][1],DP) + 1);
        }
        return dp[index][prev] = ans;
    };
    return DP(0,0,DP);
}
