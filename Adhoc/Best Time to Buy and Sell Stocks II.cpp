int Solution::maxProfit(const vector<int> &a) {
    int n= a.size();
    vector<int>dp1(2);
    vector<int>dp2(2);
    for(int i= n-1;i>=0 ; i--){
        dp1[1] = max(dp2[0]-a[i],dp2[1]);
        dp1[0] = max(dp2[1]+a[i],dp2[0]);
        dp2 = dp1;
    }
    return dp2[1];
}
