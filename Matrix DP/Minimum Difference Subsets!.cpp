int Solution::solve(vector<int> &a) {
    // let dp[i][j] denote if a sum j can be created with first i numbers
    int n = a.size();
    int sum = 0;
    for(auto &x : a) sum += x;
    int dp[n+1][sum+1] = {};
    dp[0][a[0]] = 1;
    for(int i = 1; i < n ;i++){
        for(int j = 1 ; j <= sum ; j++){
            dp[i][j] = dp[i-1][j];
            if(j-a[i] >= 1 && dp[i-1][j-a[i]]){
                dp[i][j] = 1;
            }
        }
    }
    vector<int>possible;
    int ans = 1e9;
    for(int j = 1 ; j <= sum ; j++){
        if(dp[n-1][j]) ans = min(ans,abs(sum-2*j));
    }
    return ans;
}
