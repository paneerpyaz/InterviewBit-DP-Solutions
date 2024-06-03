int Solution::longestSubsequenceLength(const vector<int> &a) {
    int n = a.size();
    if(n == 0) return 0;
    vector<int>dp1(n+1,0);
    vector<int>dp2(n+1,0);
    dp1[0] = 1;
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(a[j] < a[i]){
                dp1[i] = max(dp1[i],dp1[j] + 1);
            }
        }
    }
    dp2[n-1] = 1;
    for(int i = n-2 ; i >= 0 ; i--){
        for(int j = n-1 ; j > i ; j--){
            if(a[j] < a[i]){
                dp2[i] = max(dp2[i],dp2[j] + 1);
            }
        }
    }
    int ans = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(a[j] < a[i] ) ans = max(ans, dp1[i] + dp2[j]);
        }
    }
    ans = max({ans,dp1[n-1],dp2[0]});
    return ans;
}
