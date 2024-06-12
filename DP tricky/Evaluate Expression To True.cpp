int Solution::cnttrue(string a) {
    int dp[151][151][2];
    int n = a.size();
    int m=1003;
    memset(dp,-1,sizeof(dp));
    auto DP = [&](int i,int j,int need,auto &&DP){
        if(i>j) return 0;
        if(i==j) {
            if((need && a[i]=='T') || (!need && a[i]=='F')) return 1;
            else return 0;
        }
        if(dp[i][j][need]!=-1) return dp[i][j][need];
        int ans=0;
        for(int k=i+1; k<=j-1 ; k+=2){
            int lt=DP(i,k-1,1,DP);
            int rt=DP(k+1,j,1,DP);
            int lf=DP(i,k-1,0,DP);
            int rf=DP(k+1,j,0,DP);
            if(need){
                if(a[k]=='|'){
                    ans=(ans+(lt*rt)%m+(lt*rf)%m+(lf*rt)%m)%m;
                }
                else if(a[k]=='&'){
                    ans=(ans+(lt*rt)%m)%m;
                }
                else{
                    ans=(ans+(lt*rf)%m+(lf*rt)%m)%m;
                }
            }
            else{
                if(a[k]=='|'){
                    ans=(ans+(lf*rf)%m)%m;
                }
                else if(a[k]=='&'){
                    ans=(ans+(lf*rt)%m+(lf*rf)%m+(lt*rf)%m);
                }
                else{
                    ans=(ans+(lt*rt)%m+(lf*rf)%m)%m;
                }
            }
        }
        return dp[i][j][need]=ans;
    };
    return DP(0,n-1,1,DP);
}
