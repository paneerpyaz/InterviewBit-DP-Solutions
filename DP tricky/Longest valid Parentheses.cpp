int Solution::longestValidParentheses(string a) {
    int n=a.size();
    vector<int>dp(n+3,0);//longest par ending at i
    for(int i=1;i<n;i++){
        if(a[i]=='('){
            dp[i]=0;
        }
        else{
            if(a[i-1]=='('){
                dp[i]=dp[i-2]+2;
            }
            else if(a[i-dp[i-1]-1]=='('){
                dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}
