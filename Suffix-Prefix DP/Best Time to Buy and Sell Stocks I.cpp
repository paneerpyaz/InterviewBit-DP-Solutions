int Solution::maxProfit(const vector<int> &a) {
    int n=a.size();
    int ans=0;
    if(n==0)return 0;
    vector<int>suf(n);
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],a[i]);
    }
    for(int i=0;i<n-1;i++){
        ans=max(ans,suf[i+1]-a[i]);
    }
    return ans;
}
