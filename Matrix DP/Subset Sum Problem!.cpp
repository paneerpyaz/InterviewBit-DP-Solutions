int Solution::solve(vector<int> &a, int b) {
    int n = a.size();
    int sum = 0;
    for(auto &x : a) sum += x;
    if(sum < b) return 0;
    int dp[n+1][sum+1] = {};
    dp[0][0] = 1;
    for(int i = 1; i < n ;i++){
        for(int j = 1 ; j <= sum ; j++){
            dp[i][j] = dp[i-1][j];
            if(j-a[i] >= 1 && dp[i-1][j-a[i]]){
                dp[i][j] = 1;
            }
        }
    }
    bool ok = 0;
    for(int j = 0 ; j < n ; j++){
        if(dp[j][b]) return 1;
    }
    return 0;
}
