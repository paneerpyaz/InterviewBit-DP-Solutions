int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m] = {};
    dp[0][0] = 1;
    bool f = false;
    for(int i = 1 ; i < m ; i++){
        if(A[0][i] <= A[0][i-1]) f = true;
        if(!f){
            dp[0][i] = i+1;
        }
    }
    f = false;
    for(int i = 1 ; i < n ; i++){
        if(A[i][0] <= A[i-1][0]) f = true;
        if(!f){
            dp[i][0] = i+1;
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
             if((A[i][j] > A[i-1][j])){
                if(dp[i-1][j]>0) dp[i][j] = max(dp[i][j],dp[i-1][j]+1);
            }
            if((A[i][j] > A[i][j-1])){
                if(dp[i][j-1]>0) dp[i][j] = max(dp[i][j],dp[i][j-1]+1);
            }
        }
    }
    return (dp[n-1][m-1]>0 ? dp[n-1][m-1] : -1);
}
