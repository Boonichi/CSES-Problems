#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
struct Interval{
    ll start,end,price;
};
int cmp(Interval e1, Interval e2){
    return (e1.start <= e2.start);
}
int comparestruct(Interval e1,int e2){
    return(e1.end < e2);
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Interval> a(n);
    for (int i = 0 ; i < n; i++){
        cin >> a[i].start;
        cin >> a[i].end;
        cin >> a[i].price;
    }
    sort(a.begin(),a.end(),cmp);
    vector<ll> dp(n + 1,0);
    dp[0] = a[0].price;
    for (int i = 1; i < n; i++){
        auto low = lower_bound(a.begin(),a.end(),a[i].start,comparestruct);
        if (low - a.begin() - 1 >= 0) dp[i] = max(a[i].price, dp[low-a.begin() - 1] + a[i].price);
        else dp[i] = a[i].price;
    }
    ll res = 0;
    for (int i = 0; i < n; i++) res = max(res,dp[i]);
    cout << res << endl;
    return 0;
}