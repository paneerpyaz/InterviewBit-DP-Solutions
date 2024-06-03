int Solution::canJump(vector<int> &A) {
    int n = A.size();
    vector<bool>dp(n,false);
    dp[0] = true;
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= A[i] ; j++){
            if(j+i<n && dp[i]){
                dp[i+j] = true;
            }
        }
    }
    return dp[n-1];
}
