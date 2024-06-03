int Solution::jump(vector<int> &a) {
    int n = a.size();
    vector<int>dp(n,1e9);
    int last = 0;
    dp[0] = 0;
    for(int i = 0 ; i < n ; i++){
        if(min(n-1,a[i]+i) > last){
            for(int j = last+1 ; j <= min(n-1,a[i]+i) ; j++){
                dp[j] = min(dp[j],dp[i]+1);
            }
            last = min(n-1,a[i]+i);
        }
    }
    return (dp[n-1] == 1e9 ? -1 : dp[n-1]);
}
