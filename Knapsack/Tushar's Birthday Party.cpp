int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    //so i have to find for every possible capacity
    //the min cost req to fill from the given dishes
    //them finally add the cost
    int n = b.size();
    int maxcap = 0;
    for(auto &x : a){
        maxcap = max(x,maxcap);
    }
    vector<vector<int>>dp(n+1,vector<int>(maxcap+1,1e9));
    //initialise with infinity 
    //base case ??
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    //for filling a capacity of 0, koi paisa nahi lagega
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= maxcap ; j++){
            int notTake = dp[i-1][j];
            int Take = 1e9;
            if(j >= b[i-1]){
                Take = min(Take,dp[i][j-b[i-1]] + c[i-1]);
            }
            dp[i][j] = min(Take,notTake);
        }
    }
    int ans = 0;
    for(auto &x : a){
        ans += dp[n][x];
    }
    return ans;
}
