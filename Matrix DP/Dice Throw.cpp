int Solution::findDiceSum(int A, int B, int C) {
    int dp[A+1][C+1]={};
    //dp[i][j] += dp[i-1][j-1]+dp[i-1][j-2]...+dp[i-1][j-m];
    int m=1e9+7;
    dp[0][0]=1;
    for(int i=1;i<=A;i++){
        for(int j=1;j<=C;j++){
            dp[i][j] = (dp[i][j-1]+dp[i-1][j-1])%m;
            if(j-B-1>=0){
                dp[i][j] = (dp[i][j] -dp[i-1][j-B-1]+m)%m;
            }
        }
    }
    return dp[A][C];
}
