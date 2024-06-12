int Solution::coinchange2(vector<int> &a, int B) {
    int n=a.size(); 
    sort(a.begin(),a.end());
    int dp[B+1]={};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=B;j++){
            if(j-a[i-1]>=0){
                dp[j] += dp[j-a[i-1]];
                dp[j]%=1000007;
            }
        }
    }
    return dp[B];
}
