int Solution::minCut(string a) {
    int dp1[505][505];
    int dp2[505];
    int n = a.size();
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    auto DP1 = [&](int i,int j,auto &&DP1)->int{
        if(i == j) return 1;
        if(j == i+1) return (a[i] == a[j]);
        if(dp1[i][j] != -1) return dp1[i][j];
        return dp1[i][j] = (DP1(i+1,j-1,DP1) & (a[i] == a[j]));
    };
    auto DP2 = [&](int i,auto &&DP2)->int{
        if(i >= n) return 0;
        if(dp2[i] != -1) return dp2[i];
        int ans = 1e9;
        for(int j = i ; j < n ;j++){
            if(DP1(i,j,DP1)){
                ans = min(ans,1+DP2(j+1,DP2));
            }
        }
        return dp2[i] = ans;
    };
    return DP2(0,DP2)-1;
}
