int Solution::solve(vector<int> &a, int b) {
    int n = a.size();
    b = min(n/2, b);
    vector<vector<int>> dp(b+1,vector<int>(2,0));
    vector<vector<int>>new_dp(b+1,vector<int>(2,0));
    for (int i = n-1; i >= 0; --i) {
        for (int j = b; j >= 0; --j) {
            new_dp[j][1] = max(dp[j][1], (j < b ? dp[j+1][0] - a[i] : 0));
            new_dp[j][0] = max(dp[j][0], dp[j][1] + a[i]);
        }
        swap(dp,new_dp);
    }
    return dp[0][1];
}
