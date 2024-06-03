int Solution::chordCnt(int A) {
    vector<long long>dp(A+1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    int m = 1e9+7;
    for(int i = 3 ; i <= A ; i++){
        int ans = 0;
        for(int j = 0 ; j<i ; j++){
            dp[i] += (dp[j]%m*dp[i-j-1]%m)%m;
            dp[i] %= m;
        }
    }
    return dp[A];
}
