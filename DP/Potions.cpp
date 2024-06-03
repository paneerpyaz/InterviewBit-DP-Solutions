int Solution::minSmoke(vector<int> &a) {
    int dp[101][101];
    memset(dp,-1,sizeof(dp));
    int n = a.size();
    vector<int>pref(n+1,0);
    for(int i=1 ; i<= n ; i++){
        pref[i] = pref[i-1]+a[i-1];
    }
    auto DP = [&](int i,int j,auto &&DP){
        if(j-i==1){
            return a[i]*a[j];
        }
        if(i == j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 1e9;
        for(int mid = i ; mid <= j-1 ; ++mid){
            int s1 = (pref[mid+1]-pref[i])%100;
            int s2 = (pref[j+1]-pref[mid+1])%100;
            ans = min(ans, DP(i,mid,DP)+DP(mid+1,j,DP)+s1*s2);
        }
        return dp[i][j] = ans;
    };
    return DP(0,n-1,DP);
}
