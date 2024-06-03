int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1 ; i <= n;  i++){
        for(int j = 1 ; j <= m ; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i-1][j-1];
        }
    }
    auto good = [&](int mid){
        int sum = 0;
        bool ok = false;
        for(int i = 1 ; i <= n-mid+1 ; i++){
            for(int j = 1 ; j <= m-mid+1 ; j++){
                ok |= (dp[i+mid-1][j+mid-1]-dp[i-1][j+mid-1]-dp[i+mid-1][j-1]+dp[i-1][j-1] == mid*mid);
            }
        }
        return ok;
    };
    int l = 0, r = min(n,m),mid,ans;
    while(l <= r){
        mid = l + (r - l)/2;
        if(good(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans*ans;
}
