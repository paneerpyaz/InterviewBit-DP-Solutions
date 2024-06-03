vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int>ans;
    ans.push_back(1);
    int i1 = 0,i2 = 0,i3 = 0;
    while(D--){
        int a1 = ans[i1]*A;
        int a2 = ans[i2]*B;
        int a3 = ans[i3]*C;
        int a = min({a1,a2,a3});
        i1 += (a == a1);
        i2 += (a == a2);
        i3 += (a == a3);
        ans.push_back(a);
    }
    ans.erase(ans.begin());
    return ans;
}
