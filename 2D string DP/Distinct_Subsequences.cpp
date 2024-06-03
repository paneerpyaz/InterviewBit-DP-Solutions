int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    int dp[n+1][m+1] = {};
    for(int i = 0 ; i <= n ; i++) dp[i][0] = 1;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= m ; j++){
            if(B[j-1] == A[i-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
