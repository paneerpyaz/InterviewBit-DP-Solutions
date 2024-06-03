int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<int>dp(C+1,0);
    for(int i = 1 ; i <= n ; i++){
        vector<int>new_dp(C+1,0);
        for(int j = 0 ; j <= C ; j++){
            int notTake = dp[j];
            int Take = INT_MIN;
            if(j >= B[i-1]){
                Take = max(Take,dp[j-B[i-1]]+A[i-1]);
            }
            new_dp[j]= max(Take,notTake);
        }
        swap(new_dp,dp);
    }
    return dp[C];
}
