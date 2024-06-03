int Solution::lis(const vector<int> &a) {
    vector<int>ans;
    int n= a.size();
    ans.push_back(a[0]);
    for(int i =1 ; i < n ; i++){
        if(a[i] > ans.back()){
            ans.push_back(a[i]);
        }
        else{
            ans[lower_bound(ans.begin(),ans.end(),a[i])-ans.begin()] =a[i];
        }
    }
    return ans.size();
}
